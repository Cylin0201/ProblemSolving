#include <bits/stdc++.h>
#define INF 1e9

int N;
std::vector<int> v;
std::vector<std::vector<int>> graph;

int BFS(int start) {
    std::vector<int> dist(N + 1, INF);
    std::queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int next : graph[current]) {
            if (dist[next] == INF) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
    return *std::max_element(dist.begin() + 1, dist.end());
}

int main() {
    std::cin >> N;
    graph.assign(N + 1, {});
    v.assign(N + 1, 0);

    int x, y;
    while (true) {
        std::cin >> x >> y;
        if (x == -1 && y == -1) break;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int minPoint = INF;
    for (int i = 1; i <= N; i++) {
        v[i] = BFS(i);
        minPoint = std::min(minPoint, v[i]);
    }

    int cnt = std::count(v.begin() + 1, v.end(), minPoint);
    std::cout << minPoint << ' ' << cnt << '\n';

    for (int i = 1; i <= N; i++) {
        if (v[i] == minPoint) std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
