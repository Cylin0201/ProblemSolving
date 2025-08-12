#include <bits/stdc++.h>

int main() {
    int N, M; std::cin >> N >> M;

    std::vector<int> mem(N + 1);
    std::vector<int> cost(N + 1);

    int maxCost = 0;
    for (int i = 1; i <= N; i++) std::cin >> mem[i];
    for (int i = 1; i <= N; i++) {
        std::cin >> cost[i];
        maxCost += cost[i];
    }

    // dp[c] = 비용 c로 얻을 수 있는 최대 메모리
    std::vector<int> dp(maxCost + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int c = maxCost; c >= cost[i]; c--) {
            dp[c] = std::max(dp[c], dp[c - cost[i]] + mem[i]);
        }
    }

    int answer = maxCost;
    for (int c = 0; c <= maxCost; c++) {
        if (dp[c] >= M) {
            answer = c;
            break;
        }
    }

    std::cout << answer << "\n";
    return 0;
}
