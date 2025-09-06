#include <bits/stdc++.h>
#define INF 1e9

int N, M;
std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<int> dp, parent;

void dijkstra(int start) {
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0, start });
    dp[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if (dp[cur] < cost) continue;

        for (auto edge : graph[cur]) {
            int next = edge.first, nextCost = edge.second + cost;

            if (dp[next] > nextCost) {
                dp[next] = nextCost;
                parent[next] = cur;   // 경로 역추적용 저장
                pq.push({ -nextCost, next });
            }
        }
    }
}

int main() {
    std::cin >> N >> M;
    dp.assign(N + 1, INF);
    parent.assign(N + 1, -1);
    graph.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].push_back({ b, c });  // (도착 정점, 비용)
    }
    int start, end;
    std::cin >> start >> end;

    dijkstra(start);

    // 최단 거리 출력
    std::cout << dp[end] << '\n';

    // 경로 역추적
    std::vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    std::cout << path.size() << '\n';

    for (int v : path) std::cout << v << ' ';
    std::cout << '\n';

    return 0;
}