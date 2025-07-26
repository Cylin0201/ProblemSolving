#include <bits/stdc++.h>
#define INF 1e9

int N, M, K, X;
std::vector<std::vector<std::pair<int, int>>> v;
std::vector<int> res;

void Dijkstra(int start) {
    std::priority_queue<std::pair<int, int>> pq;
    res[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (res[current] < cost) continue;

        for (auto node : v[current]) {
            int next = node.second;
            int nextCost = cost + node.first;

            if (res[next] > nextCost) {
                res[next] = nextCost;
                pq.push({ -nextCost, next });
            }
        }
    }
}

int main() {
    std::cin >> N >> M >> K >> X;
    v.assign(N + 1, std::vector<std::pair<int, int>>());
    res.assign(N + 1, INF);

    for (int i = 0; i < M; i++) {
        int x, y; std::cin >> x >> y;
        v[x].push_back({ 1, y });
    }

    Dijkstra(X);

    bool found = false;
    for (int i = 1; i <= N; i++) {
        if (res[i] == K) {
            std::cout << i << '\n';
            found = true;
        }
    }
    if (!found) std::cout << -1 << '\n';

    return 0;
}
