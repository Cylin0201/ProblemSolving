#include <bits/stdc++.h>
#define INF INT_MAX

std::vector<std::vector<std::pair<int, int>>> a;
std::vector<int> d;

void dijkstra(int start) {
    d[start] = 0;
    std::priority_queue<std::pair<int, int>> pq;

    pq.push({ 0, start });

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (d[current] < distance) continue;

        for (const auto& edge : a[current]) {
            int next = edge.first;
            int nextDistance = distance + edge.second;

            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push({ -nextDistance, next });
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int V, E;
    std::cin >> V >> E;

    int start;
    std::cin >> start;

    a.assign(V + 1, std::vector<std::pair<int, int>>());
    d.assign(V + 1, INF);

    for (int i = 0; i < E; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        a[x].push_back({ y, w });
    }

    dijkstra(start);

    for (int i = 1; i <= V; i++) {
        if (d[i] != INF)
            std::cout << d[i] << '\n';
        else
            std::cout << "INF\n";
    }
}
