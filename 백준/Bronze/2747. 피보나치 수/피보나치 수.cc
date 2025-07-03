#include <bits/stdc++.h>

int dp[50];

int fibo(int n) {
    if (n <= 1) return dp[n];

    if (dp[n] == 0) return dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}
int main() {
    int N; std::cin >> N;
    dp[0] = 0; dp[1] = 1;

    std::cout << fibo(N) << '\n';
}