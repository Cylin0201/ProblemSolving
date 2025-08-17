#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int cnt[10001] = { 0 };
	int N, count;
	std::cin >> N;

	for (int i = 0; i < N; i++){
		std::cin >> count;
		cnt[count]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < cnt[i]; j++)
			std::cout << i << '\n';

    return 0;
}