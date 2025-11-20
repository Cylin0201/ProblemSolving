#include <bits/stdc++.h>
using namespace std;

int N; bool isArrived = false;
vector<char> v;
vector<int> cost;
vector<bool> visited;
vector<vector<int>> graph;

void DFS(int node, int money) {
    if (money < 0 || visited[node])
        return;

    // 현재 방 효과 즉시 반영
    if (v[node] == 'L') money = max(money, cost[node]);
    else if (v[node] == 'T') money -= cost[node];

    if (money < 0) return;

    if (node == N) {
        isArrived = true;
        return;
    }

    visited[node] = true;

    for (int next : graph[node]) {
        DFS(next, money);
    }

    visited[node] = false;
}

int main() {
    cin >> N;
    while (N != 0) {
        isArrived = false;
        v.assign(N + 1, 0);
        cost.assign(N + 1, 0);
        visited.assign(N + 1, false);
        graph.assign(N + 1, {});

        for (int i = 1; i <= N; i++) {
            char r; int c; cin >> r >> c;
            v[i] = r; cost[i] = c;
            int next; cin >> next;
            while (next != 0) {
                graph[i].push_back(next);
                cin >> next;
            }
        }

        DFS(1, 0);

        cout << (isArrived ? "Yes\n" : "No\n");
        cin >> N;
    }

    return 0;
}
