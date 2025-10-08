#include <bits/stdc++.h>

int dx[] = { -1 ,1 ,0 ,0 };
int dy[] = { 0 ,0 ,-1 ,1 };

int N, K; 
std::vector<std::vector<int>> map, temp;

void BFS(int vir) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] != vir) continue;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !map[nx][ny])
                    temp[nx][ny] = vir;
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(NULL);

    std::cin >> N >> K;
    map.assign(N, std::vector<int>(N, 0));

    for (int i = 0; i < N;i++)
        for (int j = 0; j < N; j++)
            std::cin >> map[i][j];
    temp = map;

    int S, X, Y; std::cin >> S >> X >> Y;

    while (S--) {
        for (int i = 1; i <= K; i++) {
            if (map[X - 1][Y - 1] > 0) {
                std::cout << map[X - 1][Y - 1] << '\n';
                return 0;
            }
            BFS(i);
            map = temp;
        }
    }
    
    std::cout << map[X - 1][Y - 1] << '\n';

    return 0;
}