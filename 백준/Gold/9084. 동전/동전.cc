#include <bits/stdc++.h>
#define MAX_SIZE 10001

std::vector<int> dp(MAX_SIZE);

int main() {
    int T; std::cin >> T;
    while (T > 0) {
        int N; std::cin >> N;
        std::vector<int> coins(N);
        for (int i = 0; i < N; i++) std::cin >> coins[i];

        int M; std::cin >> M;
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= M; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        std::cout << dp[M] << '\n';
        dp.assign(MAX_SIZE, 0);
        T--;
    }
    return 0;
}
