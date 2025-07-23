#include <bits/stdc++.h>
#define INF 1e9

int main() {
    int T; std::cin >> T;
    while (T > 0) {
        int K; std::cin >> K;
        std::vector<int> file(K + 1), sum(K + 1, 0);
        std::vector<std::vector<int>> dp(K + 1, std::vector<int>(K + 1, 0));

        for (int i = 1; i <= K; i++) {
            std::cin >> file[i];
            sum[i] = sum[i - 1] + file[i];
        }

        for (int len = 2; len <= K; len++) {
            for (int i = 1; i <= K - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                for (int k = i; k < j; k++) {
                    dp[i][j] = std::min(dp[i][j],
                        dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        std::cout << dp[1][K] << "\n";
        T--;
    }
    return 0;
}
