#include <bits/stdc++.h>

int main() {
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N;
        std::vector<std::vector<int>> v(2, std::vector<int>(N, 0));
        std::vector<std::vector<int>> dp(2, std::vector<int>(N, 0));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> v[i][j];
                if (j == 0) dp[i][j] = v[i][j];
            }
        }

        if (N > 1) {
            dp[0][1] = v[0][1] + dp[1][0];
            dp[1][1] = v[1][1] + dp[0][0];
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 2; j < N; j++) {
                dp[0][j] = v[0][j] + std::max(dp[1][j - 1], dp[1][j - 2]);
                dp[1][j] = v[1][j] + std::max(dp[0][j - 1], dp[0][j - 2]);
            }
        }

        int result = std::max(*std::max_element(dp[0].begin(), dp[0].end()), *std::max_element(dp[1].begin(), dp[1].end()));

        std::cout << result << '\n';
    }
    return 0;
}