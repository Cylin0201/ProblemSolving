#include <bits/stdc++.h>
int N, M;
std::vector<std::vector<int>> v;
std::vector<bool> visited;
std::vector<int> t;

void DFS(int node) {
    if (visited[node]) return;
    visited[node] = true;

    for (auto next : v[node]) {
        if (!visited[next]) DFS(next);
    }
}

int main() {
    std::cin >> N >> M;
    v.assign(N + 1, std::vector<int>());
    visited.assign(N + 1, false);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x; std::cin >> x;
            if (x == 1) v[i].push_back(j);
        }
    }
    for (int i = 0; i < M; i++) {
        int x; std::cin >> x;
        t.push_back(x);
    }
    DFS(t[0]);
    for (int i = 0; i < t.size(); i++) {
        if (!visited[t[i]]) {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";

    return 0;
}