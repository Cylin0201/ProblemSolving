#include <bits/stdc++.h>
using namespace std;
//맨 아래 주사위의 윗면-아랫면을 확정하면 답은 정해져 있음
//분기는 맨 아래 주사위의 윗면- 아랫면(6가지) 거기서 나머지는 그냥 최댓값으로 놓고 더하면 끝

vector<vector<int>> dice;

int result, temp;
int N;

void build(int top, int n) {
	if (n == N) return;

	int bIdx, tIdx;
	for (int i = 0; i < 6; i++) {
		if (dice[n][i] != top)
			continue;

		if (i == 0) tIdx = 5;
		else if (i == 5) tIdx = 0;
		else if (i == 1 || i == 2) tIdx = i + 2;
		else tIdx = i - 2;

		bIdx = i;
	}
	int maxScore = 0;
	for (int i = 0; i < 6; i++) {
		if (i == bIdx || i == tIdx)
			continue;

		maxScore = max(maxScore, dice[n][i]);
	}
	temp += maxScore;

	build(dice[n][tIdx], n + 1);
}

int main() {
	cin >> N;
	dice.assign(N, vector<int>(6));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 6; j++)
			cin >> dice[i][j];

	
	for (int i = 0; i < 6; i++) {
		temp = 0;
		int maxS = 0;

		int tIdx = i, bIdx;

		if (i == 0) bIdx = 5;
		else if (i == 5) bIdx = 0;
		else if (i == 1 || i == 2) bIdx = i + 2;
		else bIdx = i - 2;

		for (int j = 0; j < 6; j++) {
			if (j != tIdx && j != bIdx) {
				maxS = max(maxS, dice[0][j]);
			}
		}
		temp += maxS;

		build(dice[0][tIdx], 1); //윗면 값 넣어주기

		result = max(result, temp);
	}

	cout << result << '\n';

	return 0;
}