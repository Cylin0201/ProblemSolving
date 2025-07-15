#include <bits/stdc++.h>

int N;
std::vector<int> wines, dp;

int main() {
    std::cin >> N;
    wines.assign(N + 1, 0);
    dp.assign(N + 1, 0);

    for (int i = 1; i <= N; i++)
        std::cin >> wines[i];

    dp[1] = wines[1];
    dp[2] = dp[1] + wines[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = std::max(dp[i - 3] + wines[i - 1] + wines[i], dp[i - 2] + wines[i]);
        dp[i] = std::max(dp[i - 1], dp[i]);
    }

    std::cout << dp[N] << '\n';
    return 0;
}