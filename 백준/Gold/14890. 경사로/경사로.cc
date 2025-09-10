#include <bits/stdc++.h>

int N, L, cnt;
std::vector<std::vector<int>> map;
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };
void go(int x, int y, int dir) {
    std::vector<std::vector<bool>> used(N, std::vector<bool>(N, false));
    while (x >= 0 && x < N && y >= 0 && y < N) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // 범위를 벗어나면 성공
        if (!(nx >= 0 && nx < N && ny >= 0 && ny < N)) {
            cnt++;
            return;
        }
        // 높이 차이가 1보다 크면 실패
        if (std::abs(map[x][y] - map[nx][ny]) > 1) return;
        // 높이가 다르면 경사로 설치 필요
        if (map[x][y] != map[nx][ny]) {
            if (map[x][y] > map[nx][ny]) {
                // 내려가는 경우: 앞쪽에 경사로 설치
                int temp = map[nx][ny];
                int tx = nx, ty = ny;
                for (int i = 0; i < L; i++) {
                    if (!(tx >= 0 && tx < N && ty >= 0 && ty < N) ||
                        map[tx][ty] != temp || used[tx][ty])
                        return;
                    used[tx][ty] = true;
                    if (i < L - 1) {  // 마지막이 아닐 때만 이동
                        tx += dx[dir];
                        ty += dy[dir];
                    }
                }
            }
            else {
                // 올라가는 경우: 뒤쪽에 경사로 설치
                int temp = map[x][y];
                int tx = x, ty = y;
                for (int i = 0; i < L; i++) {
                    if (!(tx >= 0 && tx < N && ty >= 0 && ty < N) ||
                        map[tx][ty] != temp || used[tx][ty])
                        return;
                    used[tx][ty] = true;
                    if (i < L - 1) {  // 마지막이 아닐 때만 이동
                        tx -= dx[dir];
                        ty -= dy[dir];
                    }
                }
            }
        }
        x = nx; y = ny;
    }
}
int main() {
    std::cin >> N >> L;
    map.assign(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> map[i][j];
    // 가로 길 체크
    for (int i = 0; i < N; i++) {
        go(i, 0, 0);    // 각 행을 오른쪽으로
    }
    // 세로 길 체크
    for (int j = 0; j < N; j++) {
        go(0, j, 1);    // 각 열을 아래쪽으로
    }
    std::cout << cnt << '\n';
    return 0;
}