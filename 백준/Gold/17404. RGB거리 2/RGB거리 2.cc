#include <bits/stdc++.h>
#define INF 1e9

int main() {
    int N; std::cin >> N;
    std::vector<std::vector<int>> RGB(N, std::vector<int>(3));
    std::vector<std::vector<int>> dp(N, std::vector<int>(3, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++)
            std::cin >> RGB[i][j];
    }
    
    int result = INF;

    for (int firstColor = 0; firstColor < 3; firstColor++) {
        dp[0][firstColor] = RGB[0][firstColor];
        for (int otherColor = 0; otherColor < 3; otherColor++) {
            if (firstColor != otherColor) dp[0][otherColor] = INF;
        }

        for (int i = 1; i < N; i++) {
            dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + RGB[i][0];
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + RGB[i][1];
            dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + RGB[i][2];
        }

        for (int lastColor = 0; lastColor < 3; lastColor++) {
            if (lastColor == firstColor) continue;
            result = std::min(result, dp[N - 1][lastColor]);
        }
    }

    std::cout << result << '\n';

    return 0;
}