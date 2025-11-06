#include <bits/stdc++.h>

int main() {
    int T; std::cin >> T;
    
    while (T-- > 0) {
        int N, M, K; std::cin >> N >> M;
        std::vector<std::vector<int>> dist(N + 1, std::vector<int>(N + 1, 1e9));

        for (int i = 1; i <= N; i++)
            dist[i][i] = 0;

        for (int i = 0; i < M; i++) {
            int a, b, d; std::cin >> a >> b >> d;
            dist[a][b] = d;
            dist[b][a] = d;
        }
        std::cin >> K;
        std::vector<int> starts(K);
        for (int i = 0; i < K; i++) {
            std::cin >> starts[i];
        }

        std::vector<std::pair<int, int>> sumDist(N + 1, { 0, 0 });

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i == j) continue;
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (const auto& s : starts) {
            for (int i = 1; i <= N; i++) {
                sumDist[i].first++;
                sumDist[i].second += dist[s][i];
            }
        }

        int startIdx = 1;
        for (int i = 1; i <= N; i++) {
            if (sumDist[i].first == K) {
                startIdx = i;
                break;
            }
        }

        int minIdx = startIdx;

        for (int i = startIdx + 1; i <= N; i++) {
            if (sumDist[i].first == K && sumDist[i].second < sumDist[minIdx].second)
                minIdx = i;
        }

        std::cout << minIdx << '\n';
    }
    return 0;
}