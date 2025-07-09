#include <bits/stdc++.h>
int one = INT_MAX, two = INT_MAX, three = INT_MAX;

int main() {
	std::vector<int> dice(6);
	int N;  std::cin >> N;
	long long result = 0;
	long long sum = 0; 

	for (int i = 0; i < 6; i++) {
		std::cin >> dice[i];
		sum += dice[i];
	}
	int max_serface = *std::max_element(dice.begin(), dice.end());

	for (int i = 0; i < 6; i++) {
		one = std::min(one, dice[i]);
		for (int j = i + 1; j < 6; j++) {
			if (i + j == 5) continue;
			two = std::min(dice[i] + dice[j], two);
			for (int k = j + 1; k < 6; k++) {
				if (i + k == 5 || j + k == 5) continue;
				three = std::min(three, dice[i] + dice[j] + dice[k]);
			}
		}
	}
	if (N == 1) result = sum - max_serface;
	
	else {
		result += 4LL * three; 
		result += ((8LL * N - 12) * two); 
		result += (5LL * N - 6) * (N - 2) * one;
	}

	std::cout << result << '\n';
}