#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;

	while (T-- > 0) {
		int N; cin >> N;
		vector<int> result;
		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;

		int mid;
		for (int i = 1; i <= N; i++) {
			int input; cin >> input;

			if (i == 1) mid = input;
			else if (mid < input) minHeap.push(input);
			else maxHeap.push(input);

			if (!(i % 2)) continue;

			if (maxHeap.size() == minHeap.size()) {
				result.push_back(mid);
				continue;
			}

			if (maxHeap.size() > minHeap.size()) {
				minHeap.push(mid);
				mid = maxHeap.top();
				maxHeap.pop();
			}
			else if (maxHeap.size() < minHeap.size()) {
				maxHeap.push(mid);
				mid = minHeap.top();
				minHeap.pop();
			}

			result.push_back(mid);
		}
		cout << result.size();

		for (int i = 0; i < result.size(); i++) {
			if (!(i % 10)) cout << '\n';
			cout << result[i] << ' ';
		}
	}

	return 0;
}