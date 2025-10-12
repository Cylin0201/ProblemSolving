#include <bits/stdc++.h>

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int N, M;
std::vector<std::vector<int>> map;
std::vector<std::pair<int, int>> sharks;

int BFS(int x, int y) {
    std::vector<std::vector<int>> dist(N, std::vector<int>(M, 0));
    std::queue<std::pair<int, int>> q;
    q.push({ x, y });
    dist[x][y] = 1;

    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        if (map[cx][cy] == 1)
            return dist[cx][cy] - 1;

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (!(nx >= 0 && nx < N && ny >= 0 && ny < M && !dist[nx][ny]))
                continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }
    return 0; 
}

int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 1)
                sharks.push_back({ i, j });
        }
    }

    int safe = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0)
                safe = std::max(safe, BFS(i, j));
        }
    }

    std::cout << safe << '\n';
    return 0;
}
