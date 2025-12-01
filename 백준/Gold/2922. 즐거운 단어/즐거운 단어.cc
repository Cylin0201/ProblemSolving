#include <bits/stdc++.h>

using namespace std;

string input;
vector<int> vowels = { 'A', 'E', 'I', 'O', 'U' };

bool isVowel(char ch) {
	return find(vowels.begin(), vowels.end(), ch) != vowels.end();
}

long long dfs(int idx, int ja, int mo, bool containL) {
	if (ja >= 3 || mo >= 3) return 0;
	if (idx == input.size()) return containL; // 0 또는 1 

	long long ans = 0;
	if (input[idx] == '_') {
		ans += dfs(idx + 1, ja + 1, 0, containL) * 20;
		ans += dfs(idx + 1, ja + 1, 0, true);
		ans += dfs(idx + 1, 0, mo + 1, containL) * 5;
	}
	else {
		if (isVowel(input[idx])) {
			ans += dfs(idx + 1, 0, mo + 1, containL);
		}
		else {
			if (input[idx] == 'L') {
				ans += dfs(idx + 1, ja + 1, 0, true);
			}
			else {
				ans += dfs(idx + 1, ja + 1, 0, containL);
			}
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> input;

	cout << dfs(0, 0, 0, false);

	return 0;
}