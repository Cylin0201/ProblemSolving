#include <bits/stdc++.h>
using namespace std;

int main() {
	string input; cin >> input;

	unordered_map<string, int> um;


	for (int w = 1; w <= input.size(); w++) {
		for (int i = 0; i < input.size() - w + 1; i++) {
			um[input.substr(i, w)]++;
		}
	}

	cout << um.size() << '\n';

	return 0;
}