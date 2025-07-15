#include <bits/stdc++.h>

const int INF = 1e9;
int N, E;
std::vector<std::vector<std::pair<int, int>>> graph;

std::vector<int> dijkstra(int start) {
    std::vector<int> dp(N + 1, INF);
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0, start });
    dp[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dp[current] < cost) continue;

        for (const auto& edge : graph[current]) {
            int next = edge.second;
            int nextCost = cost + edge.first;

            if (nextCost < dp[next]) {
                dp[next] = nextCost;
                pq.push({ -nextCost, next });
            }
        }
    }
    return dp;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> E;
    graph.assign(N + 1, std::vector<std::pair<int, int>>());

    for (int i = 0; i < E; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        graph[x].push_back({ w, y });
        graph[y].push_back({ w, x });
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    auto distFrom1 = dijkstra(1);
    auto distFromV1 = dijkstra(v1);
    auto distFromV2 = dijkstra(v2);

    long long route1 = 1LL * distFrom1[v1] + distFromV1[v2] + distFromV2[N];
    long long route2 = 1LL * distFrom1[v2] + distFromV2[v1] + distFromV1[N];

    long long answer = std::min(route1, route2);
    
    if (answer >= INF) std::cout << -1 << '\n';
    else std::cout << answer << '\n';

    return 0;
}
