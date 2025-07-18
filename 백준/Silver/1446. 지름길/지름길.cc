#include <bits/stdc++.h>

int N, D;
std::vector<int> dp;
std::vector<std::vector<std::pair<int, int>>> v;

void dijkstra(int start) {
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0, start });
    dp[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().second, distance = -pq.top().first;
        pq.pop();

        if (dp[current] < distance) continue;
        for (auto elem : v[current]) {
            int next = elem.second, nextDistance = distance + elem.first;
            if (nextDistance < dp[next]) {
                dp[next] = nextDistance;
                pq.push({ -nextDistance, next });
            }
        }
    }
}

int main() {
    std::cin >> N >> D;
    dp.assign(D + 1, 1e9);
    v.assign(D + 1, std::vector<std::pair<int, int>>());

    for (int i = 0; i < N; i++) {
        int s, e, distance;
        std::cin >> s >> e >> distance;
        if (e > D) continue;
        v[s].push_back({ distance, e });
    }

    for (int i = 0; i < D; i++) {
        v[i].push_back({ 1, i + 1 });
    }

    dijkstra(0);

    std::cout << dp[D] << '\n';
}