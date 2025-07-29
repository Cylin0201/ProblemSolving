#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> map, temp;
int dx[] = { -1, 1, 0 ,0 }, dy[] = { 0, 0 , -1, 1 };

int BFS() {
    std::vector<std::vector<std::vector<bool>>> visited(N, std::vector<std::vector<bool>>(M, std::vector<bool>(2, false)));

    std::queue<std::tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = true;

    int dist = 1;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y, broken] = q.front();
            q.pop();

            if (x == N - 1 && y == M - 1) return dist;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                // 벽이 아님
                if (map[nx][ny] == 0 && !visited[nx][ny][broken]) {
                    visited[nx][ny][broken] = true;
                    q.push({ nx, ny, broken });
                }
                // 벽이고 아직 부순 적이 없음
                else if (map[nx][ny] == -1 && broken == 0 && !visited[nx][ny][1]) {
                    visited[nx][ny][1] = true;
                    q.push({ nx, ny, 1 });
                }
            }
        }
        dist++;
    }

    return -1;
}

int main() {
    std::cin >> N >> M;
    temp.assign(N, std::vector<int>(M));

    for (int i = 0; i < N; i++) {
        std::string input; std::cin >> input;
        for (int j = 0; j < M; j++) {
            temp[i][j] = (input[j] == '0' ? 0 : -1);
        }
    }

    map = temp;

    int result = BFS();

    std::cout << result << '\n';
    return 0;
}
