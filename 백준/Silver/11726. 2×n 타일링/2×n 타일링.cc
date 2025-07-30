#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> dp(N + 1, 0);
    dp[1] = 1; dp[2] = 2;

    for (int i = 3; i <= N; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    std::cout << dp[N] % 10007 << '\n';

    return 0;
}