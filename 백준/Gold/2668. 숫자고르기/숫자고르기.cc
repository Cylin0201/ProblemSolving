#include <bits/stdc++.h>

int N;
std::vector<int> v;
std::vector <bool> visited;
std::vector<int> ans;

void DFS(int curr, int start) {
    if (visited[curr]) {
        if (start == curr) ans.push_back(curr);
        return;
    }

    visited[curr] = true;
    DFS(v[curr], start);
}

int main(){
    std::cin >> N;
    v.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
        std::cin >> v[i];

    // 사이클에 속한 노드들을 전부 선택
    for (int i = 1; i <= N; i++) {
        visited.assign(N + 1, false);
        DFS(i, i);
    }

    std::cout << ans.size() << "\n";
    for (auto x : ans)
        std::cout << x << "\n";

    return 0;
}