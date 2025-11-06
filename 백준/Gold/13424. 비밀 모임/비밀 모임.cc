#include <bits/stdc++.h>

int N, M, K;
std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<int> dist, sumDist;

void dijkstra(int start) {
    dist.assign(N + 1, 1e9);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cur = pq.top().second, distance = -pq.top().first;
        pq.pop();

        if (dist[cur] < distance) continue;

        for (const auto& elem : graph[cur]) {
            int next = elem.second, nextDistance = elem.first + distance;

            if (dist[next] > nextDistance) {
                dist[next] = nextDistance;
                pq.push({ -nextDistance, next });
            }
        }
    }
}

int main() {
    int T; std::cin >> T;

    while (T-- > 0) {
        std::cin >> N >> M;
        graph.assign(N + 1, {});
        for (int i = 0; i < M; i++) {
            int a, b, d; std::cin >> a >> b >> d;
            graph[a].push_back({ d, b });
            graph[b].push_back({ d, a });
        }
        std::cin >> K;
        sumDist.assign(N + 1, 0);
        for (int i = 0; i < K; i++) {
            int start; std::cin >> start;
            dijkstra(start);
            for (int j = 1; j <= N; j++)
                sumDist[j] += dist[j];
        }

        int minIdx = 1;
        for (int i = 2; i <= N; i++) {
            if (sumDist[i] < sumDist[minIdx]) minIdx = i;
        }
        std::cout << minIdx << '\n';
    }

    return 0;
}