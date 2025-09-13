#include <bits/stdc++.h>

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N, M;
std::vector<std::vector<char>> map;
std::vector<std::vector<int>> dist;
std::vector<std::pair<int, int>> v;
std::vector<std::vector<bool>> visited;
void BFS(int x, int y) {
    std::queue<std::pair<int, int>> q;
    
    for (auto elem : v) {   //* 위치
        q.push({ elem });
        dist[elem.first][elem.second] = -1;
    }
    q.push({ x, y });   //고슴도치 위치
    dist[x][y] = 1;

    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for (int i = 0 ; i < 4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 'X' && !dist[nx][ny]) {    //돌이 아니고, 물이나 고슴도치가 없는 곳으로
                if (dist[cx][cy] < 0 && map[nx][ny] != 'D') { //물일 때
                    dist[nx][ny] = -1;
                    q.push({ nx , ny });
                }
                else if (dist[cx][cy] > 0) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
}
int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<char>(M));
    dist.assign(N, std::vector<int>(M, 0));
    int sx, sy, ex, ey;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 'S') {
                sx = i; sy = j;
            }
            else if (map[i][j] == 'D') {
                ex = i; ey = j;
            }
            else if (map[i][j] == '*') {
                v.push_back({ i, j });
            }
        }
    }

    BFS(sx, sy);

    if (!dist[ex][ey]) std::cout << "KAKTUS\n";
    else std::cout << dist[ex][ey] - 1 << '\n';
    return 0;
}