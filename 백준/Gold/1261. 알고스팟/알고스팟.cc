#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> dist;
std::vector<std::string> graph;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS(int x, int y) {
    std::deque<std::pair<int, int>> dq;
    dq.push_back({ x, y });
    dist[x][y] = 0;

    while (!dq.empty()) {
        int cx = dq.front().first, cy = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                int cost = dist[cx][cy] + (graph[nx][ny] - '0');
                if (dist[nx][ny] > cost) {
                    dist[nx][ny] = cost;
                    if (graph[nx][ny] == '1') dq.push_back({ nx, ny });  
                    else dq.push_front({ nx, ny }); 
                }
            }
        }
    }
}

int main() {
    std::cin >> M >> N;
    graph.assign(N, std::string());
    dist.assign(N, std::vector<int>(M, INT_MAX));

    for (int i = 0; i < N; i++)
        std::cin >> graph[i];

    BFS(0, 0);

    std::cout << dist[N - 1][M - 1] << '\n';

    return 0;
}
