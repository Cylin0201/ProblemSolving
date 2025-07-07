#include <bits/stdc++.h>

int main() {
    int n; std::cin >> n;
    std::vector<int> score(n + 1);
    std::vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> score[i];
    }

    dp[0] = 0;
    dp[1] = score[1];
    if (n >= 2) dp[2] = score[1] + score[2];
    if (n >= 3) dp[3] = std::max(score[1] + score[3], score[2] + score[3]);

    for (int i = 4; i <= n; ++i) {
        dp[i] = std::max(dp[i - 2] + score[i],
            dp[i - 3] + score[i - 1] + score[i]);
    }

    std::cout << dp[n] << std::endl;
    return 0;
}
