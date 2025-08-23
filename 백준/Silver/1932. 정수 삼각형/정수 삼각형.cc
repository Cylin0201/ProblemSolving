#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<std::vector<int>> v(N, std::vector<int>());
    std::vector<std::vector<int>> dp(N, std::vector<int>());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int input; std::cin >> input;
            v[i].push_back(input);
            dp[i].push_back(0);
        }
    }
    dp[0][0] = v[0][0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j] + v[i][j];
            else if (j == i) dp[i][j] = dp[i - 1][j - 1] + v[i][j];
            else dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1]) + v[i][j];
        }
    }

    std::cout << *std::max_element(dp[N - 1].begin(), dp[N - 1].end()) << '\n';

    return 0;
}