#include <bits/stdc++.h>


int N, M;
std::vector<std::vector<int>> v;
std::vector<bool> visited;
std::vector<int> nodeColor;

void DFS(int node, int color) {
    if (visited[node]) return;
    visited[node] = true;
    
    nodeColor[node] = color;

    for (auto& next : v[node]) {
        if (!visited[next]) DFS(next, (nodeColor[node] + 1) % 2);
    }
}

bool checkBinary() {
    for (int i = 1; i <= N; i++) {
        for (int j : v[i]) {
            if (nodeColor[i] == nodeColor[j]) return false;
        }
    }
    return true;
}


int main() {
    int K; std::cin >> K;
    while (K--) {
        std::cin >> N >> M;
        v.assign(N + 1, std::vector<int>());
        visited.assign(N + 1, false);
        nodeColor.assign(N + 1, -1);

        for (int i = 0; i < M; i++) {
            int x, y; std::cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for (int i = 1; i <= N; i++) {  
            if (!visited[i]) DFS(i, 0);
        }
        std::string result = (checkBinary()) ? "YES" : "NO";
        std::cout << result << '\n';

    }
    return 0;
}