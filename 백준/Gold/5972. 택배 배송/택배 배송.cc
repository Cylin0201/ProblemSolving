#include <bits/stdc++.h>

std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<int> dp;

void dijkstra(int start) {
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0, start });  //cost, next

    while (!pq.empty()) {
        int current = pq.top().second; int cost = -pq.top().first;
        pq.pop();
        if (cost > dp[current]) continue;

        for (const auto& edge : graph[current]) {
            int next = edge.second; int nextCost = edge.first + cost;
            if (nextCost  < dp[next]) {
                dp[next] = nextCost;
                pq.push({ -nextCost, next });
            }
        }
    }
}

int main() {
    int N, M; std::cin >> N >> M;
    graph.assign(N + 1, std::vector<std::pair<int, int>>());
    dp.assign(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        int x, y, w; std::cin >> x >> y >> w;
        graph[x].push_back({ w, y });
        graph[y].push_back({ w, x });
    }

    dijkstra(1);

    std::cout << dp[N] << '\n';
}