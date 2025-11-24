#include <bits/stdc++.h>
using namespace std;

int N; 
int dx[] = { 1, 0 }; int dy[] = { 0, 1 };
vector<vector<int>> m, dist;
vector<vector<pair<int, int>>> graph;

void dijkstra(int x, int y) {
	priority_queue < pair<int, pair<int, int>>> pq;
	pq.push({ 0, {x, y} });

	while (!pq.empty()) {
		int d = -pq.top().first;
		int cx = pq.top().second.first, cy = pq.top().second.second;
		pq.pop();

		if (dist[cx][cy] < d) continue;

		for (int i = 0; i < 2; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;

			int nextDistance = m[nx][ny] - m[cx][cy];
			if (nextDistance >= 0) nextDistance += d + 1;
			else nextDistance = d;

			if (nextDistance < dist[nx][ny]) {
				dist[nx][ny] = nextDistance;
				pq.push({ -nextDistance, {nx, ny} });
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> N;
	m.assign(N + 1, vector<int>(N + 1, 0));
	dist.assign(N + 1, vector<int>(N + 1, 1e9));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> m[i][j];

	dijkstra(1, 1);
	cout << dist[N][N] << '\n';

	return 0;
}