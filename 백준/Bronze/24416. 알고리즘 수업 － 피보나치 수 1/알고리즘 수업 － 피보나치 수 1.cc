#include <bits/stdc++.h>

int cnt_recursive, cnt_dp;
int dp[41];

int fib_recursive(int n) {
    if (n == 1 || n == 2) {
        cnt_recursive++;
        return 1;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_dp(int n) {
    if (n == 1 || n == 2) return dp[n];
 
    for (int i = 3; i <= n; i++) {
        cnt_dp++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    dp[1] = 1; dp[2] = 2;

    int N;  std::cin >> N;
    fib_dp(N); fib_recursive(N);

    std::cout << cnt_recursive << ' ' << cnt_dp << '\n';
    return 0;
}