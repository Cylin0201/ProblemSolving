#include <bits/stdc++.h>
using namespace std;

int N, M, T;
vector<vector<int>> m;
vector<vector<vector<int>>> v;

vector<vector<int>> rotate(const vector<vector<int>>& mat) {
	int r = mat.size(), c = mat[0].size();
	vector<vector<int>> res(c, vector<int>(r, 0));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			res[j][r - 1 - i] = mat[i][j]; // 시계 90도 회전

	return res;
}

bool check(int j, int k, vector<vector<int>>& r) {
	for (int x = 0; x < r.size(); x++) {
		for (int y = 0; y < r[0].size(); y++) {
			if (r[x][y] == 1 && m[x + j][y + k] == 1)
				return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M >> T;
	m.assign(N, vector<int>(M, 0));

	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		vector<vector<int>> t(a, vector<int>(b));
		for (int j = 0; j < a; j++)
			for (int k = 0; k < b; k++)
				cin >> t[j][k];

		v.push_back(t);
	}

	// 스티커 순회
	for (int i = 0; i < v.size(); i++) {

		bool attached = false;
		auto r = v[i];

		// 4번 회전 시도
		for (int rot = 0; rot < 4 && !attached; rot++) {

			int R = r.size();
			int C = r[0].size();

			for (int j = 0; j <= N - R && !attached; j++) {
				for (int k = 0; k <= M - C; k++) {

					if (check(j, k, r)) {
						for (int x = 0; x < R; x++)
							for (int y = 0; y < C; y++)
								if (r[x][y] == 1)
									m[x + j][y + k] = 1;

						attached = true;
						break;
					}
				}
			}

			// 못 붙였으면 회전
			if (!attached)
				r = rotate(r);
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (m[i][j] == 1) cnt++;

	cout << cnt << '\n';

	return 0;
}
