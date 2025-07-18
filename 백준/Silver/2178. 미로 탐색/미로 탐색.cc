#include <bits/stdc++.h>

int N, M;
std::vector<std::string> graph;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0 ,-1, 1 };

int BFS(int x, int y) {
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dist(N, std::vector<int>(M, 0));
    dist[x][y] = 1;
    q.push({ x, y });

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i], ny = current.second + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && graph[nx][ny] == '1') {
                graph[nx][ny] = '0';
                dist[nx][ny] += dist[current.first][current.second] + 1;
                q.push({ nx, ny });
            }
        }
    }
    return dist[N - 1][M - 1];
}

int main() {
    std::cin >> N >> M;
    graph.assign(N, std::string());
    for (int i = 0; i < N; i++) {
        std::cin >> graph[i];
    }
    std::cout<< BFS(0, 0)<< '\n';

}