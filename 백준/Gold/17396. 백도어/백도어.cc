#include <bits/stdc++.h>

int N, M;
std::vector<long long> a, dp;
std::vector<std::vector<std::pair<int, int>>> graph;

void dijkstra(int n) {
    std::priority_queue<std::pair<long long, int>> pq;
    pq.push({ 0, n }); //{거리, 시작지점}
    
    while (!pq.empty()) {
        int current = pq.top().second; long long distance = -pq.top().first;
        pq.pop();

        if (dp[current] < distance) continue;
        if (a[current] == 1 && current != N - 1) continue;

        for (auto elem : graph[current]) {
            int next = elem.second; long long nextDistance = elem.first + distance;
            if (dp[next] > nextDistance) {
                dp[next] = nextDistance;
                pq.push({ -nextDistance, next });
            }
        }
    }
}

int main() {
    std::cin >> N >> M;
    a.assign(N, 0);
    dp.assign(N, LLONG_MAX);
    graph.assign(N, {});
    for (int i = 0; i < N; i++)
        std::cin >> a[i];

    for (int i = 0; i < M; i++) {
        int a, b, d; std::cin >> a >> b >> d;
        graph[a].push_back({ d, b });   //양방향
        graph[b].push_back({ d, a });
    }   
    dp[0] = 0;
    dijkstra(0);

    if (dp[N - 1] == LLONG_MAX) std::cout << -1 << '\n';
    else std::cout << dp[N - 1] << '\n';
    return 0;
}