#include <bits/stdc++.h>

bool check_graph(const std::vector<std::vector<int>>& graph) {
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            if (graph[i][j] == 0) return false;
    return true;
}

int BFS(std::vector<std::vector<int>>& graph) {
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == 1) q.push({ i, j });
        }
    }

    int x = 0, y = 0;
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < graph.size() && ny >= 0 && ny < graph[x].size() && graph[nx][ny] == 0) {
                q.push({ nx, ny });
                graph[nx][ny] = graph[x][y] + 1;
            }
        }
    }

    if (!check_graph(graph)) return -1;
    return graph[x][y] - 1;
}

int main() {
    int N, M; std::cin >> N >> M;
    std::vector<std::vector<int>> graph(M, std::vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) std::cin >> graph[i][j];

    std::cout << BFS(graph) << '\n';
}