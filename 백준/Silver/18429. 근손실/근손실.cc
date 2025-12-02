#include <bits/stdc++.h>

using namespace std;

int N, M, res;
vector<int> v;
vector<bool> visited;

void DFS(int weight, int days) {
	if (weight < 500)
		return;

	if (days == N) {
		res++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		DFS(weight - M + v[i], days + 1);
		visited[i] = false;
	}

}

int main() {
	cin >> N >> M;
	v.assign(N, 0);
	visited.assign(N, false);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	DFS(500, 0);

	cout << res << '\n';

	return 0;
}