#include <bits/stdc++.h>

int N, cnt;
std::vector<std::vector<int>> board;
std::vector<int> col, diag1, diag2;

bool check(int x, int y) {
    if (col[y]) return false;
    if (diag1[x + y]) return false;
    if (diag2[x - y + N - 1]) return false;
    
    return true;
}

void nQueen(int x, int y) {
    if (!check(x, y)) return ;

    if (x == N - 1) {
        cnt++; return;
    }

    board[x][y] = 1;
    col[y] = diag1[x + y] = diag2[x - y + N - 1] = 1;

    for (int ny = 0; ny < N; ny++) {
        if (y != ny) nQueen(x + 1, ny);
    }

    board[x][y] = 0;
    col[y] = diag1[x + y] = diag2[x - y + N - 1] = 0;

}

int main() {
    std::cin >> N;
    board.assign(N, std::vector<int>(N, 0));

    col.assign(N, 0);
    diag1.assign(2 * N, 0);
    diag2.assign(2 * N, 0);

    for (int i = 0 ; i < N; i++)
        nQueen(0, i);

    std::cout << cnt << '\n';
    return 0;
}