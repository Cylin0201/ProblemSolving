#include <bits/stdc++.h>

int N;
int main() {
    std::cin >> N;

    int max_dp[2][3] = { 0 };
    int min_dp[2][3] = { 0 };
    int curr[3]; // 현재 입력값

    for (int j = 0; j < 3; j++) {
        std::cin >> curr[j];
        max_dp[0][j] = curr[j];
        min_dp[0][j] = curr[j];
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 3; j++) std::cin >> curr[j];

        max_dp[1][0] = curr[0] + std::max(max_dp[0][0], max_dp[0][1]);
        max_dp[1][1] = curr[1] + std::max({ max_dp[0][0], max_dp[0][1], max_dp[0][2] });
        max_dp[1][2] = curr[2] + std::max(max_dp[0][1], max_dp[0][2]);

        min_dp[1][0] = curr[0] + std::min(min_dp[0][0], min_dp[0][1]);
        min_dp[1][1] = curr[1] + std::min({ min_dp[0][0], min_dp[0][1], min_dp[0][2] });
        min_dp[1][2] = curr[2] + std::min(min_dp[0][1], min_dp[0][2]);

        for (int j = 0; j < 3; j++) {
            max_dp[0][j] = max_dp[1][j];
            min_dp[0][j] = min_dp[1][j];
        }
    }

    int max_val = std::max({ max_dp[0][0], max_dp[0][1], max_dp[0][2] });
    int min_val = std::min({ min_dp[0][0], min_dp[0][1], min_dp[0][2] });

    std::cout << max_val << ' ' << min_val << '\n';
}
