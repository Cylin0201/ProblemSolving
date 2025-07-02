#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

bool check1[1001] = { false, }, check2[1001] = { false, };
std::vector<int> vec[1001];

void bfs(int start, bool check[]) {
    std::queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";
        for (int i = 0; i < vec[current].size(); i++) {
            int next = vec[current][i];
            if (!check[next]) {
                q.push(next);
                check[next] = true;
            }
        }
    }
}

void dfs(int start, bool check[]) {
    if (check[start]) return;

    check[start] = true;
    std::cout << start << " ";
    for (int i = 0; i < vec[start].size(); i++) {
        int next = vec[start][i];
        if (!check[next]) dfs(next, check);
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(NULL);

    int N, M, V; std::cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b; std::cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        if (!vec[i].empty()) std::sort(vec[i].begin(), vec[i].end());
    }

    dfs(V, check1);
    std::cout << "\n";
    bfs(V, check2);
}