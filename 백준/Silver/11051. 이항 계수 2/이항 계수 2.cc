#include <bits/stdc++.h>

int main() {
    int N, K; std::cin >> N >> K;
    std::vector<std::vector<int>> dp(1001, std::vector<int>(1001, 0));
    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    std::cout << dp[N][K] << '\n';

}