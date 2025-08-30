#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> visited;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

int DFS(int x, int y, int size, int score) {
    visited[x][y] = true;
    score += map[x][y];

    if (size == 4) {
        visited[x][y] = false; // 백트래킹
        return score;
    }

    int result = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
            result = std::max(result, DFS(nx, ny, size + 1, score));
        }
    }

    visited[x][y] = false; // 백트래킹
    return result;
}

int getSpecial(int x, int y) {
    int result = 0;
    if (x + 1 < N && y + 2 < M)
        result = std::max(result, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
    if (x + 2 < N && y + 1 < M)
        result = std::max(result, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
    if (x - 1 >= 0 && y + 2 < M)
        result = std::max(result, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1]);
    if (x + 2 < N && y - 1 >= 0)
        result = std::max(result, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1]);
    return result;
}

int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M));
    visited.assign(N, std::vector<bool>(M, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> map[i][j];

    int maxScore = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maxScore = std::max(maxScore, DFS(i, j, 1, 0));
            maxScore = std::max(maxScore, getSpecial(i, j));
        }
    }

    std::cout << maxScore << '\n';
    return 0;
}
