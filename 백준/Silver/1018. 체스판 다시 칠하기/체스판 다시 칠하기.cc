#include <bits/stdc++.h>

std::string chess1[8] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
std::string chess2[8] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW", "WBWBWBWB" };

int check_board(int x, int y, const std::vector<std::string>& v) {
    int result1 = 0, result2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (v[x + i][y + j] != chess1[i][j]) result1++;
            if (v[x + i][y + j] != chess2[i][j]) result2++;
        }
    }
    return result1 < result2 ? result1 : result2;
}

int main() {
    int N, M; std::cin >> N >> M;
    std::vector<std::string> board(N);
    int min = 64;
    for (int i = 0; i < N; i++)
        std::cin >> board[i];

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            if (check_board(i, j, board) < min)
                min = check_board(i, j, board);
        }
    }
    std::cout << min << '\n';
}