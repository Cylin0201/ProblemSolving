#include <bits/stdc++.h>
#define INF 1e9

int main() {
    int N, M; std::cin >> N >> M;
    std::vector<std::vector<int>> dist(N + 1, std::vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int x, y, z; std::cin >> x >> y >> z;
        dist[x][y] = std::min(dist[x][y], z);
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) std::cout << 0 << ' ';
            else std::cout << dist[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}