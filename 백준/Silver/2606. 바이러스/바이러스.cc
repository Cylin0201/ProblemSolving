#include <iostream>
#include <vector>

bool visited[101] = { false };
int cnt = -1;

void DFS(const std::vector<std::vector<int>>& v, int start) {
    if (visited[start]) return;
    visited[start] = true;
    cnt++;

    for (int i = 0; i < v[start].size(); i++)
        DFS(v, v[start][i]);
}   

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(NULL);

    int N, K; std::cin >> N >> K;
    std::vector<std::vector<int>> graph(N+1, std::vector<int>());

    for (int i = 0; i < K; i++) {
        int x, y; std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    DFS(graph, 1);
    std::cout << cnt << "\n";
}