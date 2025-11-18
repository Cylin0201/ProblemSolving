#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N, M, T;
vector<string> m;
vector<pair<int, int>> v;

int main() {
	cin >> N >> M >> T;
	m.assign(N, "");

	int t = 1;
	for (int i = 0 ; i < N; i++){
		cin >> m[i];
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 'O') v.push_back({i, j});
		}
	}

	while (t != T){
		t++;
		//비어 있는 곳에 모든 폭탄 놓기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				m[i][j] = 'O';
			}
		}

		if (t == T)
			break;

		t++;
		//처음 설치해둔 폭탄 폭발
		for (auto [x, y] : v) {
			m[x][y] = '.';
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!(nx >= 0 && nx < N && ny >= 0 && ny < M))
					continue;
				m[nx][ny] = '.';
			}
		}
		v.clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (m[i][j] == 'O') v.push_back({i, j});
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << m[i][j];
		}
		cout<<'\n';
	}

	return 0;
}