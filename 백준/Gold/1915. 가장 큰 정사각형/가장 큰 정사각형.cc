#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> map, dp;

int main() {
    std::cin >> N >> M;
    map.assign(N, std::vector<int>(M));
    dp.assign(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        std::string input; std::cin >> input;
        for (int j = 0; j < input.size(); j++) {
            map[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 || j == 0) dp[i][j] = map[i][j];
            else {
                if (map[i][j] == 1) dp[i][j] = std::min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result = std::max(result, dp[i][j]);
        }
    }
    std::cout << result * result << '\n';
    return 0;
}