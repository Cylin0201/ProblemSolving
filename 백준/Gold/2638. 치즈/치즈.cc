#include <bits/stdc++.h>

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M;
int t;
std::vector<std::vector<int>> map, cnt;
std::vector<std::vector<bool>> visited;

bool isExternalAir(int x, int y) {
    bool result = false;
    std::queue<std::pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (!(nx >= 0 && nx < N && ny >= 0 && ny < M)) { //벽에 닿으면
                result = true;
                continue;
            }

            if (!visited[nx][ny]) {
                q.push({ nx ,ny });
                visited[nx][ny] = true;
            }
        }
    }
    return result;
}

void meltCheese(int x, int y) {
    std::queue<std::pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] > 0) {
                    cnt[nx][ny]++;
                    continue;
                }
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

bool isDone() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 1) return false;
    return true;
}

int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> map[i][j];

    while (!isDone()) {
        visited.assign(N, std::vector<bool>(M, false));
        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0 && !visited[i][j] && isExternalAir(i, j))
                    v.push_back({ i, j });
            }
        }

        visited.assign(N, std::vector<bool>(M, false));
        cnt.assign(N, std::vector<int>(M, 0));
        for (int i = 0; i < v.size(); i++)
            meltCheese(v[i].first, v[i].second);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && cnt[i][j] >= 2)
                    map[i][j] = 0;
            }
        }
        t++;
    }
    std::cout << t << '\n';  

    return 0;
}
