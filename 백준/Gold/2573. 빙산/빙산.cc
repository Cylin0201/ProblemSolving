#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> ice;
std::vector<std::vector<int>> melted;

std::vector<std::vector<bool>> visited;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void DFS(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && ice[nx][ny] > 0 && !visited[nx][ny])
            DFS(nx, ny);
    }
}

int getCntOfCluster() {
    visited.assign(N, std::vector<bool>(M, false));
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ice[i][j] > 0 && !visited[i][j]) {
                DFS(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void meltIce() {
    melted.assign(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ice[i][j] > 0) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && ice[nx][ny] == 0)
                        melted[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ice[i][j] -= melted[i][j];
            if (ice[i][j] < 0) ice[i][j] = 0;
        }
    }
}

int main() {
    std::cin >> N >> M;
    ice.assign(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> ice[i][j];

    int t = 0;
    while (true) {
        int cnt = getCntOfCluster();
        if (cnt == 0) {
            std::cout << 0 << '\n';
            return 0;
        }
        if (cnt >= 2) break;

        meltIce();
        t++;
    }
    std::cout << t << '\n';

    return 0;
}