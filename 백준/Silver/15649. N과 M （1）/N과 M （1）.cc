#include <bits/stdc++.h>

int N, M; 
std::vector<std::vector<int>> graph;
std::vector<bool> visited;
std::vector<int> path;

void DFS(int node, int level) {
    visited[node] = true;
    path.push_back(node);

    if (level == 1) {
        for (int i = 0; i < path.size(); i++) {
            std::cout << path[i] << (i + 1 == path.size() ? '\n' : ' ');
        }
    }
    else {
        for (auto next : graph[node]) {
            if (!visited[next])
                DFS(next, level - 1);
        }
    }
    visited[node] = false;
    path.pop_back();
}

int main() {
    std::cin >> N >> M;
    graph.assign(N + 1, std::vector<int>());
    visited.assign(N + 1, false);


    for (int node = 1; node <= N; node++) {
        for (int next = 1; next <= N; next++) {
            if (node == next) continue;
            graph[node].push_back(next);
        }
    }

    for (int node = 1; node <= N; node++)
        DFS(node, M);
}