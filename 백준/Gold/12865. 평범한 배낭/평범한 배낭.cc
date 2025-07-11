#include <bits/stdc++.h>

int main() {
    int N, W; std::cin >> N >> W;

    std::vector<int> weight(N + 1), value(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> weight[i] >> value[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (w < weight[i])
                dp[i][w] = dp[i - 1][w];  // 물건 i를 넣을 수 없음
            else
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);  // 넣을지 말지 선택
        }
    }

    std::cout << dp[N][W] << '\n';
}
