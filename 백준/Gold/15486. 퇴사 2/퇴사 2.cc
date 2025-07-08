#include <bits/stdc++.h>

int N;
std::vector<int> T, P, dp;

int main() {
    std::cin >> N;
    T.resize(N + 1); P.resize(N + 1); dp.resize(N + 2);

    for (int i = 1; i <= N; i++) {
        std::cin >> T[i] >> P[i];
    }
    int currentMax = 0;

    for (int i = 1; i <= N; i++) {
        currentMax = std::max(currentMax, dp[i]);
        if (i + T[i] > N + 1) continue;
        dp[i + T[i]] = std::max(dp[i + T[i]], currentMax + P[i]);
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}