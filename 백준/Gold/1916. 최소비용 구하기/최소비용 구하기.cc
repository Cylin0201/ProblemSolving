#include <bits/stdc++.h>

std::vector <std::vector<std::pair<int, int>>> graph;
std::vector<int> dp;

void dijkstra(int start) {
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (distance > dp[current]) continue;

        for (const auto& edge : graph[current]) {
            int next = edge.second;
            int nextDistance = edge.first + distance;

            if (dp[next] > nextDistance) {
                dp[next] = nextDistance;
                pq.push({ -nextDistance, next });
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
    }
    int start, end; std::cin >> start >> end;

    dijkstra(start);

    std::cout << dp[end] << '\n';
}