#include <bits/stdc++.h>
#define MAX_DEPTH 5

int N, M;
std::vector<std::vector<int>> graph;
std::vector<bool> visited;
int c;

void DFS(int vertex, int depth) {
    if (depth == MAX_DEPTH) {
        c++;
        return;
    }

    visited[vertex] = true;
    for (auto next : graph[vertex]) {
        if (!visited[next]) {
            DFS(next, depth + 1);
        }
    }
    visited[vertex] = false;
}

int main() {
    std::cin >> N >> M;
    graph.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < M; i++) {
        int x, y; std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 1);
        if (c > 0) break;
    }
    if (c > 0) std::cout << 1 << '\n';
    else std::cout << 0 << '\n';
    return 0;

}