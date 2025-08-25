#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> dp(100001, -1);
    dp[0] = 0, dp[2] = 1, dp[4] = 2, dp[5] = 1;

    for (int i = 6; i <= N; i++) {
        if (i % 5 == 0) dp[i] = dp[i - 5] + 1;
        else if ((i - 5) % 2 == 0 || i % 2 == 0) dp[i] = dp[i - 2] + 1;
    }

    std::cout << dp[N] << '\n';

    return 0;
}