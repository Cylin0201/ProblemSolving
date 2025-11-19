#include <bits/stdc++.h>
using namespace std;

int dir[] = {-1, 1};

int N;
bool isOk = false;
vector<vector<char>> m;
vector<pair<int,int>> teachers;

bool check() {
	for (const auto& [tx, ty] : teachers) {
		for (int i = 0 ; i < 2; i++){
			int nUp = tx + dir[i];
			while (nUp >= 1 && nUp <= N) {
				if (m[nUp][ty] == 'O')
					break;
				if (m[nUp][ty] == 'S')
					return false;
				nUp += dir[i];
			}
		}

		for (int i = 0; i < 2; i++) {
			int nR = ty + dir[i];
			while (nR >= 1 && nR <= N) {
				if (m[tx][nR] == 'O')
					break;
				if (m[tx][nR] == 'S')
					return false;
				nR += dir[i];
			}
			
		}
	}
	return true;
}

void DFS(int x, int y, int obs) {
	if (check()) {
		isOk = true; return ;
	}
	if (obs == 0) return ;

	if (y == N + 1) {
		x++; y = 1;
	}
	if (x == N + 1) return;

	if (m[x][y] != 'X')
		DFS(x, y + 1, obs);
	
	else{
		m[x][y] = 'O';
		DFS(x, y + 1, obs - 1);
		m[x][y] = 'X';

		DFS(x, y + 1, obs);
	}
}

int main() {
	cin >> N;
	m.assign(N + 1, vector<char>(N + 1, 0));
	for (int i = 1 ; i <= N; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> m[i][j];
			if (m[i][j] == 'T') teachers.push_back({i, j});
		}
	}

	DFS(1, 1, 3);

	if (isOk) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}