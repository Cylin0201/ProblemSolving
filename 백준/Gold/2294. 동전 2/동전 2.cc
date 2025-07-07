#include <bits/stdc++.h>
#define MAX_VALUE 100001

int dp[10001];
int coin[101];
int N, value;

int F(int n) {
    if (n < 0) return MAX_VALUE;
    if (n == 0) return 0;

    if (dp[n] != -1) return dp[n];

    int result = MAX_VALUE;
    for (int i = 1; i <= N; ++i)
        result = std::min(result, F(n - coin[i]) + 1);

    return dp[n] = result;
}

int main() {
    std::cin >> N >> value;
    for (int i = 1; i <= N; i++) {
        std::cin >> coin[i];
    }

    std::fill(dp, dp + 10001, -1);

    int answer = F(value);
    if (answer == MAX_VALUE) std::cout << -1 << '\n'; 
    else std::cout << answer << '\n';

    return 0;
}