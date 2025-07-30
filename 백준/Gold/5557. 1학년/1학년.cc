#include <bits/stdc++.h>
int N;
std::vector<int> v;
long long dp[101][21]; // dp[수 index][현재 합]

int main() {
    std::cin >> N;
    v.assign(N, 0);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    dp[0][v[0]] = 1; // 첫 수는 고정

    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j] > 0) {
                if (j + v[i] <= 20) dp[i][j + v[i]] += dp[i - 1][j];
                if (j - v[i] >= 0)  dp[i][j - v[i]] += dp[i - 1][j];
            }
        }
    }

    std::cout << dp[N - 2][v[N - 1]] << '\n';
    return 0;
}
