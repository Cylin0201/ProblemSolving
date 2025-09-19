#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> graph, reverse;
std::vector<bool> visited;
int cnt, res;

void DFS(int node, std::vector<std::vector<int>>& graph) {
    for (const auto& next : graph[node]) {
        if (!visited[next]) {
            visited[next] = true;
            cnt++;
            DFS(next, graph);
        }
    }
}

int main() {
    std::cin >> N >> M;
    graph.assign(N + 1, {});
    reverse.assign(N + 1, {});
    
    for (int i = 0; i < M; i++) {
        int a, b; std::cin >> a >> b;
        graph[a].push_back(b);
        reverse[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {  
        visited.assign(N + 1, false);
        DFS(i, graph);

        visited.assign(N + 1, false);
        DFS(i, reverse);

        if (cnt == N - 1) res++;
        cnt = 0;
    }
    std::cout << res << '\n';

    return 0;
}