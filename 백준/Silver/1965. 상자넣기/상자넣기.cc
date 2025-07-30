#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> v(N),dp(N, 1);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) dp[i] = std::max(dp[j] + 1, dp[i]);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
}