#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> coins(N);
    for (int i = 0; i < N; ++i)
        std::cin >> coins[i];

    std::vector<long long> dp(M + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= M; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    std::cout << dp[M] << '\n';
}