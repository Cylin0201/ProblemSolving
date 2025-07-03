#include <bits/stdc++.h>

int dp[1000];

int solve(int n) {
    if (n <= 2) return dp[n];

    if (n % 2) {
        if (dp[n] != 0) return dp[n];
        return dp[n] = (2 * solve(n - 1) - 1) % 10007;
    }
    else {
        if (dp[n] != 0) return dp[n];
        return dp[n] = (2 * solve(n - 1) + 1) % 10007;
    }
}

int main() {
    int n; std::cin >> n;
    dp[1] = 1; dp[2] = 3;

    std::cout << solve(n) << '\n';
}