#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> map, dp;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

int DFS(int x, int y) {
    if (x == N - 1 && y == M - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[x][y] > map[nx][ny]) {
            dp[x][y] += DFS(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M));
    dp.assign(N, std::vector<int>(M, -1)); // -1로 초기화

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> map[i][j];

    std::cout << DFS(0, 0) << '\n';
    return 0;
}
