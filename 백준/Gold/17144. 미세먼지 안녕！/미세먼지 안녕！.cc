#include <bits/stdc++.h>

int N, M, T;
std::vector<std::vector<int>> map;
int dx[] = { 0, -1, 0, 1 };     //우, 상, 좌, 하
int dy[] = { 1, 0, -1, 0 };     

int ux[] = {0, 1, 0, -1};
int uy[] = {1, 0, -1, 0};   

int result;

int main() {
    std::cin >> N >> M >> T;
    map.assign(N, std::vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> map[i][j];
    
    //공기청정기 위치 초기화
    std::pair<int, int>up = { 0,0 }, down = { 0, 0 };
    for (int i = 0; i < N; i++) {
        if (map[i][0] == -1) {
            if (up.first == 0) up.first = i;
            else {
                down.first = i;
                break;
            }
        }
    }
    
    for (int t = 0; t < T; t++) {
        //미세먼지 확산 알고리즘
        std::vector<std::vector<int>> add(N, std::vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0) {
                    int temp = map[i][j];
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != -1) {
                            add[nx][ny] += map[i][j] / 5;
                            temp -= map[i][j] / 5;
                        }
                    }
                    map[i][j] = temp;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] += add[i][j];
            }
        }

        // 위쪽 공기청정기 (반시계)
        for (int i = up.first - 1; i > 0; i--) map[i][0] = map[i - 1][0];            // 아래로 당김
        for (int j = 0; j < M - 1; j++) map[0][j] = map[0][j + 1];                   // 왼쪽으로 당김
        for (int i = 0; i < up.first; i++) map[i][M - 1] = map[i + 1][M - 1];       // 위로 당김
        for (int j = M - 1; j > 1; j--) map[up.first][j] = map[up.first][j - 1];    // 오른쪽으로 당김
        map[up.first][1] = 0; 

        // 아래쪽 공기청정기 (시계)
        for (int i = down.first + 1; i < N - 1; i++) map[i][0] = map[i + 1][0];     // 위로 당김
        for (int j = 0; j < M - 1; j++) map[N - 1][j] = map[N - 1][j + 1];          // 왼쪽으로 당김
        for (int i = N - 1; i > down.first; i--) map[i][M - 1] = map[i - 1][M - 1]; // 아래로 당김
        for (int j = M - 1; j > 1; j--) map[down.first][j] = map[down.first][j - 1]; // 오른쪽으로 당김
        map[down.first][1] = 0; 
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result += (map[i][j] > 0) ? map[i][j] : 0;
        }
    }
    std::cout << result << '\n';
}