#include <bits/stdc++.h>

int R, C, K;
std::vector<std::vector<char>> map;
std::vector<std::vector<bool>> visited;
int cnt;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int x, int y, int len) {
    if (x == 0 && y == C - 1) { 
        if (len == K) cnt++;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
            !visited[nx][ny] && map[nx][ny] == '.') {
            DFS(nx, ny, len + 1);
        }
    }   
    visited[x][y] = false; 
}

int main() {
    std::cin >> R >> C >> K;
    map.assign(R, std::vector<char>(C));
    visited.assign(R, std::vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> map[i][j];
        }
    }

    DFS(R - 1, 0, 1); 
    std::cout << cnt << '\n';

}
