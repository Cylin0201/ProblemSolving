#include <bits/stdc++.h>

int N, root_idx, M;
std::vector<std::vector<int>> graph;
int cnt;

void DFS(int node) {
    if (node == M) return;

    bool isLeaf = true;
    for (int child : graph[node]) {
        if (child != M) {
            isLeaf = false;
            DFS(child);
        }
    }

    if (isLeaf) cnt++;
}

int main() {
    std::cin >> N;
    graph.assign(N, std::vector<int>());

    for (int i = 0; i < N; i++) {
        int input; std::cin >> input;
        if (input != -1) graph[input].push_back(i);
        else root_idx = i;
    }

    std::cin >> M;

    if (M == root_idx) {
        std::cout << 0 << '\n';
        return 0;
    }

    DFS(root_idx);
    std::cout << cnt << '\n';

    return 0;
}
