#include <bits/stdc++.h>
int N, L, R;
std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> visited;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool BFS(int sx, int sy) {
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> union_cells;

    q.push({ sx, sy });
    visited[sx][sy] = true;
    union_cells.push_back({ sx, sy });
    int total = map[sx][sy];

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                int diff = abs(map[x][y] - map[nx][ny]);
                if (diff >= L && diff <= R) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                    union_cells.push_back({ nx, ny });
                    total += map[nx][ny];
                }
            }
        }
    }

    // 연합이 2개 이상이어야 이동 발생
    if (union_cells.size() == 1) return false;

    int average = total / union_cells.size();
    for (auto [x, y] : union_cells)
        map[x][y] = average;

    return true;
}

int main() {
    std::cin >> N >> L >> R;
    map.assign(N, std::vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> map[i][j];

    int days = 0;
    while (true) {
        visited.assign(N, std::vector<bool>(N, false));
        bool moved = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!visited[i][j])
                    if (BFS(i, j)) moved = true;

        if (!moved) break;
        days++;
    }

    std::cout << days << '\n';
    return 0;
}
