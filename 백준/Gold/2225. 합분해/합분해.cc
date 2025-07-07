#include <bits/stdc++.h>
#define MOD 1000000000

long long dp[201][201];

int main() {
    int N, M; std::cin >> N >> M;

    for (int i = 0; i <= N; i++) dp[i][1] = 1;
    for (int i = 1; i <= M; i++) dp[0][i] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    std::cout << dp[N][M] << '\n';
}
