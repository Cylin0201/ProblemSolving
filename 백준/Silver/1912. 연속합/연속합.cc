#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> v(N), dp(N);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    int maxVal = v[0];
    dp[0] = v[0];

    for (int i = 1; i < N; i++) {
        dp[i] = std::max(dp[i - 1] + v[i], v[i]);
        maxVal = std::max(dp[i], maxVal);
    }

    std::cout << maxVal << '\n';
    return 0;   
}