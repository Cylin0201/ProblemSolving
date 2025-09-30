    #include <bits/stdc++.h>

    std::vector<std::pair<int, int>> v;
    std::vector<std::vector<int>> board(9, std::vector<int>(9));
    int cnt = 0;


    void printBoard() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    bool check(int x, int y) {
        int seen[10] = { 0 };

        // 세로
        for (int i = 0; i < 9; i++) {
            int val = board[i][y];
            if (val != 0 && seen[val]++) return false;
        }

        std::fill(seen, seen + 10, 0);

        // 가로
        for (int j = 0; j < 9; j++) {
            int val = board[x][j];
            if (val != 0 && seen[val]++) return false;
        }

        std::fill(seen, seen + 10, 0);

        // 3x3
        int cx = (x / 3) * 3, cy = (y / 3) * 3;
        for (int i = cx; i < cx + 3; i++) {
            for (int j = cy; j < cy + 3; j++) {
                int val = board[i][j];
                if (val != 0 && seen[val]++) return false;
            }
        }

        return true;
    }

    void DFS(int n) {
        if (cnt > 0) return;

        if (n == v.size()) {
            cnt++;
            printBoard();
            return;
        }

        int x = v[n].first, y = v[n].second;

        for (int num = 1; num <= 9; num++) {
            board[x][y] = num;
            if (check(x, y)) {
                DFS(n + 1);
            }
            board[x][y] = 0;
        }
    }

    int main() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cin >> board[i][j];
                if (board[i][j] == 0) v.push_back({ i, j });
            }
        }

        DFS(0);
        return 0;
    }