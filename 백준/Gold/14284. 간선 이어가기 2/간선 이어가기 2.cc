#include <bits/stdc++.h>
using namespace std;

int N, M;
int s, t;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cur = pq.top().second, distance = -pq.top().first;
        pq.pop();

        if (dist[cur] < distance) continue;

        for (auto elem : graph[cur]) {
            int next = elem.first, nextDistance = elem.second + distance;
            if (dist[next] > nextDistance) {
                dist[next] = nextDistance;
                pq.push({ -nextDistance, next });
            }
        }
    }
}

int main() {
    cin >> N >> M;
    graph.assign(N + 1, {});
    dist.assign(N + 1, 1e9);

    for (int i = 0; i < M; i++) {
        int x, y, d; cin >> x >> y >> d;
        graph[x].push_back({ y, d });
        graph[y].push_back({ x, d });
    }
    cin >> s >> t;

    dijkstra(s);

    cout << dist[t] << '\n';

    return 0;
}