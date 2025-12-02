#include <bits/stdc++.h>

using namespace std;

int N, M, res;
vector<int> v;
vector<bool> visited;

void DFS(int kit, int weight, int days) {
	if (weight < 500)
		return;

	if (days == N) {
		res++;
		return;
	}

	if (visited[kit]) return;
	visited[kit] = true;
	
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		DFS(i, weight - M + v[i], days + 1);
	}

	visited[kit] = false;
}

int main() {
	cin >> N >> M;
	v.assign(N, 0);
	visited.assign(N, false);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 0; i < N; i++) 
		DFS(i, 500 - M + v[i], 1);

	cout << res << '\n';

	return 0;
}