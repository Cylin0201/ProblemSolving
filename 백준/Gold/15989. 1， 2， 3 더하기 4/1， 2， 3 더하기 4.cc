#include <bits/stdc++.h>

std::vector<std::vector<int>> dp(10001, std::vector<int>(4));

int main() {
    int T; std::cin >> T;
    while (T > 0) {
        int N; std::cin >> N;

        for (int i = 1; i <= N; i++) {
            dp[i][1] = 1;
        }
        dp[2][2] = dp[3][3] = 1;

        for (int i = 3; i <= N; i++) {
            dp[i][2] = dp[i - 2][2] + dp[i - 2][1];
        }
        for (int i = 4; i <= N; i++) {
            dp[i][3] = dp[i - 3][3] + dp[i - 3][2] + dp[i - 3][1];
        }

        std::cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
        T--;
    }
    return 0;
}