#include <bits/stdc++.h>

std::vector<std::vector<int>> m1, m2;
int cnt;

void change(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            m2[i][j] = (m2[i][j] == 1) ? 0 : 1;
        }
    }
    cnt++;
}


int main() {
    int N, M; std::cin >> N >> M;
    m1.resize(N, std::vector<int>(M));
    m2.resize(N, std::vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; std::cin >> c;
            m1[i][j] = c - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; std::cin >> c;
            m2[i][j] = c - '0';
        }
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (m1[i][j] != m2[i][j]) change(i, j);
        }
    }
    if (m1 == m2) std::cout << cnt << '\n';
    else std::cout << -1 << '\n';
}