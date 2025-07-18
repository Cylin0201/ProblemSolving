#include <bits/stdc++.h>

int N;
std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> result;
std::vector<bool> visited;

void DFS(int start, int node) {
    for (auto next : graph[node]) {
        if (!visited[next]) {
            visited[next] = true;
            result[start][next] = 1;
            DFS(start, next);
        }
    }
}

int main() {
    std::cin >> N; 
    graph.assign(N, std::vector<int>());
    result.assign(N, std::vector<int>(N, 0));

    int input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> input;
            if (input == 1) graph[i].push_back(j);
        }
    }

    for (int i = 0; i < N; i++) {
        visited.assign(N, false);
        DFS(i, i);
    }

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << ' ';
        }
        std::cout << '\n';
    }
}