#include <bits/stdc++.h>

int N;
std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> visited;
std::vector<int> result(101);

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void DFS(int safe, int x, int y) {
    if (visited[x][y] == 0) {
        visited[x][y] = safe;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0)
                DFS(safe, nx, ny);
        }
    }
}

int main() {
     std::cin >> N;
     graph.assign(N, std::vector<int>(N));
     visited.assign(N, std::vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> graph[i][j];
    
    for (int rain = 0; rain <= 100; rain++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (rain >= graph[i][j]) //잠기는 경우
                    visited[i][j] = -1;
            }
        }

        int safe = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (rain < graph[i][j] && visited[i][j] == 0)
                    DFS(++safe, i, j);
            }
        }

        result[rain] = safe;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) visited[i][j] = 0;
    }
    std::cout << *std::max_element(result.begin(), result.end()) << '\n';
}