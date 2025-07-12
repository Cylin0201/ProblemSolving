#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> board(N);
    for (int i = 0; i < N; ++i)
        std::cin >> board[i];

    int maxLen = std::min(N, M);

    int result = 1;

    for (int len = maxLen; len >= 1; len--) {
        for (int i = 0; i <= N - len; i++) {
            for (int j = 0; j <= M - len; j++) {
                char val = board[i][j];
                if (val == board[i][j + len - 1] &&
                    val == board[i + len - 1][j] &&
                    val == board[i + len - 1][j + len - 1]) {
                    result = len * len;
                    std::cout << result << std::endl;
                    return 0;
                }
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}
