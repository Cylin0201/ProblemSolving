#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> map;
std::vector<std::vector<int>> dist;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int x, int y) {
    std::queue<std::pair<int, int>> q;
    q.push({ x, y });
    dist[x][y] = 0;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == 1 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M));
    dist.assign(N, std::vector<int>(M, -1));

    int startX = -1, startY = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    BFS(startX, startY);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0)
                std::cout << 0 << " ";
            else
                std::cout << dist[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
