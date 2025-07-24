#include <bits/stdc++.h>

int M, N, H;
std::vector<std::vector<std::vector<int>>> map;
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

struct pos3d {
    int x, y, z;
    pos3d(int x, int y, int z):x(x),y(y),z(z){}
    pos3d() { x = 0; y = 0; z = 0; }
};

bool checkNeverAged() {       //모두 익지못하는 상태 == -1
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j][h] == 0) return true;
            }
        }
    }
    return false;
}

 int BFS() {
    std::queue<pos3d> q;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j][h] == 1) q.push({ i, j, h });
            }
        }
    }
    
    pos3d current;
    while (!q.empty()) {
        current = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = current.x + dx[i], ny = current.y + dy[i], nz = current.z + dz[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H && map[nx][ny][nz] == 0) {
                q.push({ nx, ny, nz });
                map[nx][ny][nz] = map[current.x][current.y][current.z] + 1;
            }
        }
    }


    if (checkNeverAged()) return -1;
    return map[current.x][current.y][current.z] - 1;
}

int main() {
    std::cin >> M >> N >> H;
    map.assign(N, std::vector<std::vector<int>>(M, std::vector<int>(H , 0)));

    bool allAged = true;
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cin >> map[i][j][h];
                if (map[i][j][h] == 0) allAged = false;
            }
        }
    }
    if (allAged) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::cout<< BFS()<<'\n';

    return 0;
}