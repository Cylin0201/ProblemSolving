#include <bits/stdc++.h>
using namespace std;

int N, M, k;
vector<int> cost, parent;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

bool isUnion(int a, int b) {
	return getParent(a) == getParent(b);
}

void unionParent(int a, int b) {
	a = getParent(a); b = getParent(b);

	if (cost[a] > cost[b]){
		parent[a] = b;
		cost[a] = 0;
	}
	else if (cost[b] > cost[a]) {
		parent[b] = a;
		cost[b] = 0;
	}
	else {
		if (a < b) {
			parent[b] = a;
			cost[b] = 0;
		}
		else {
			parent[a] = b;
			cost[a] = 0;
		}
	}
}

int main() {
	cin >> N >> M >> k;
	cost.assign(N + 1, 0);
	parent.assign(N + 1, 0);

	for (int i = 1; i <= N; i++){
		parent[i] = i;
		cin >> cost[i];
	}

	for (int i = 0; i < M; i++) {
		int v, w; cin>> v >> w;
		if (!isUnion(v, w)) unionParent(v, w);
		else {
			if (v > w) {
				parent[v] = w;
				cost[v] = 0;
			}
			else {
				parent[w] = v;
				cost[w] = 0;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++)
		sum += cost[i];

	if (sum > k) cout<<"Oh no\n";
	else cout<<sum<<'\n';

	return 0;
}