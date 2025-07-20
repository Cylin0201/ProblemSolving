#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> map;
int maxSize = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int getSafetyArea(const std::vector<std::vector<int>>& temp) {
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (temp[i][j] == 0) cnt++;
    return cnt;
}

void spreadVirus(std::vector<std::vector<int>>& temp) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 2) {
                std::queue<std::pair<int, int>> q;
                q.push({ i, j });
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir], ny = y + dy[dir];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && temp[nx][ny] == 0) {
                            temp[nx][ny] = 2;
                            q.push({ nx, ny });
                        }
                    }
                }
            }
        }
    }
}

void buildWalls(int count) {
    if (count == 3) {
        std::vector<std::vector<int>> temp = map;
        spreadVirus(temp);
        maxSize = std::max(maxSize, getSafetyArea(temp));
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                buildWalls(count + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> map[i][j];

    buildWalls(0);
    std::cout << maxSize << '\n';
}