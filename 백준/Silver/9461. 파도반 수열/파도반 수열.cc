#include <bits/stdc++.h>

long long dp[101];

long long P(int n) {
    if (n <= 3) return dp[n];

    if (dp[n] != 0) return dp[n];
    return dp[n] = P(n - 2) + P(n - 3);
}

int main() {
    dp[1] = dp[2] = dp[3] = 1;
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N;
        std::cout << P(N) << '\n';
    }
}