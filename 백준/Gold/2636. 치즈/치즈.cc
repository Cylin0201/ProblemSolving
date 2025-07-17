#include <bits/stdc++.h>

std::vector<std::vector<int>> graph;
std::vector<std::vector<bool>> visited;
std::vector<int> counts;
int N, M;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 외부 공기 영역을 BFS로 탐색해서 visited에 표시
void bfs_air() {
    visited.assign(N, std::vector<bool>(M, false));
    std::queue<std::pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && graph[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

// 외부 공기와 맞닿은 치즈인지 판별
bool is_outer_cheese(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny]) {
            return true;
        }
    }
    return false;
}

int getCheeses() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 1) cnt++;
        }
    }
    counts.push_back(cnt);
    return cnt;
}

int main() {
    std::cin >> N >> M;
    graph.assign(N, std::vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> graph[i][j];
        }
    }

    int time = 0;
    while (getCheeses() > 0) {
        bfs_air(); // 외부 공기 체크
        std::vector<std::pair<int, int>> to_melt;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 1 && is_outer_cheese(i, j)) {
                    to_melt.push_back({ i, j });
                }
            }
        }

        for (auto [x, y] : to_melt) {
            graph[x][y] = 0;
        }

        time++;
    }

    std::cout << time << '\n';
    std::cout << counts[counts.size() - 2] << '\n';
}
