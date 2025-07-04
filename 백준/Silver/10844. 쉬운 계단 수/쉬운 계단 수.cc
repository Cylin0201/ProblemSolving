#include <bits/stdc++.h>
#define MOD 1000000000

long long dp[101][11];

int main() {
    int N; std::cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            if (j < 9) dp[i][j] += dp[i - 1][j + 1];
        dp[i][j] %= MOD;
        }
    }
    long long result = 0;
    for (int i = 0; i <= 9; i++)
        result = (result + dp[N][i]) % MOD;

    std::cout << result << '\n';

    return 0;
}