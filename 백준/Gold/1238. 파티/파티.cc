#include <bits/stdc++.h>
#define INF 1e9

int N, M, X;
std::vector<int> dist;
std::vector<std::vector<std::pair<int, int>>> graph;

void dijkstra(int start) {
    std::vector<int> v(N + 1, INF);
    v[start] = 0;
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second, distance = -pq.top().first;
        pq.pop();

        if (v[current] < distance) continue;

        for (const auto& elem : graph[current]) {
            int next = elem.first, nextDistance = elem.second + distance;
            if (nextDistance < v[next]) {
                v[next] = nextDistance;
                pq.push({ -nextDistance, next });
            }
        }
    }
    if (start == X) {
        for (int i = 1; i <= N; i++) {
            if (i != X) dist[i] += v[i];
        }
    }
    else  dist[start] = v[X];
}


int main() {
    std::cin >> N >> M >> X;
    dist.assign(N + 1, 0);
    graph.assign(N + 1, std::vector < std::pair<int, int>>());

    for (int i = 0; i < M; i++) {
        int x, y, z; std::cin >> x >> y >> z;
        graph[x].push_back({ y, z });
    }

    //1. 가는 최단거리 구하기(X를 제외한 모든 출발점에서 X로의 최단거리)
    for (int i = 1; i <= N; i++) {
        if (i != X) dijkstra(i);
    }

    //2. 오는 최단거리 구하기 (출발점이 X에서 다른 모든 종착지까지의 최단거리)
    dijkstra(X);


    //3. 최단거리끼리 더하고, 최댓값을 출력하기
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = std::max(result, dist[i]);
    }
    std::cout << result << '\n';

    return 0;
}