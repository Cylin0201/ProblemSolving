#include <bits/stdc++.h>
#define INF 1e9

int main() {
    int N; std::cin >> N;

    std::vector<std::pair<int, int>> m(N + 1);
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        std::cin >> m[i].first >> m[i].second;
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i <= N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                dp[i][j] = std::min(dp[i][j],
                    dp[i][k] + dp[k + 1][j] + m[i].first * m[k].second * m[j].second);
            }
        }
    }

    std::cout << dp[1][N] << '\n';
    return 0;
}