#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> map;
std::vector<std::pair<int, int>> cctv;
int ans = 1e9;
int dx[4] = { 0, -1, 0, 1 }; // 우, 상, 좌, 하
int dy[4] = { 1, 0, -1, 0 };

void check(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if (map[nx][ny] == 6) return;
        if (map[nx][ny] != 0) continue;
        map[nx][ny] = -1;
    }
}

void dfs(int idx) {
    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!map[i][j]) cnt++;

        ans = std::min(ans, cnt);
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    std::vector<std::vector<int>> tmp;

    for (int dir = 0; dir < 4; dir++) {
        tmp = map;

        if (map[x][y] == 1)
            check(x, y, dir);
        else if (map[x][y] == 2) {
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (map[x][y] == 3) {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (map[x][y] == 4) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        else if (map[x][y] == 5) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx + 1);
        // case 종료이므로 초기화
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                map[i][j] = tmp[i][j];
    }
}

int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6)
                cctv.push_back({ i, j });
        }
    }

    dfs(0);
    std::cout << ans << '\n';

    return 0;
}