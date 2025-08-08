#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> dp(N + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }

    std::cout << dp[N] << '\n';
}
