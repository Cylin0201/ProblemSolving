#include <bits/stdc++.h>

int main() {
    int T; std::cin >> T;
    while (T--) {
        int N, M; std::cin >> N;
        std::vector<int> coins(N);
        for (int i = 0; i < N; i++)
            std::cin >> coins[i];
        std::cin >> M;

        std::vector<int> dp(M + 1, 0);
        dp[0] = 1;  // 0원을 만드는 방법 1가지

        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= M; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        std::cout << dp[M] << '\n';
    }
    return 0;
}