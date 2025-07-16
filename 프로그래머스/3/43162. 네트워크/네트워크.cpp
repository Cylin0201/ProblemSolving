#include <bits/stdc++.h>

std::vector<bool> visited;

void DFS(int node, const std::vector<std::vector<int>>& computers, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && computers[node][i] == 1) {
            DFS(i, computers, n);
        }
    }
}

int solution(int n, std::vector<std::vector<int>> computers) {
    visited.assign(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, computers, n);
            count++;
        }
    }
    return count;
}
