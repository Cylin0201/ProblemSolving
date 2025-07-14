#include <bits/stdc++.h>
int N;
int players[20]; // 1: 스타트 팀, 0: 링크 팀
std::vector<std::vector<int>> S;
int minDiff = INT_MAX;

void F(int start, int cnt) {
    if (cnt == N / 2) {
        std::vector<int> start, link;

        for (int i = 0; i < N; i++) {
            if (players[i] == 1) start.push_back(i);
            else link.push_back(i);
        }

        int startSum = 0, linkSum = 0;

        // 각 팀의 능력치 계산
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                if (i == j) continue;
                startSum += S[start[i]][start[j]];
                linkSum += S[link[i]][link[j]];
            }
        }

        int diff = abs(startSum - linkSum);
        minDiff = std::min(minDiff, diff);
        return;
    }

    for (int i = start + 1; i < N; i++) {
        players[i] = 1;
        F(i, cnt + 1);
        players[i] = 0;
    }
}

int main() {
    std::cin >> N;
    S.assign(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> S[i][j];

    players[0] = 1;
    F(0, 1);

    std::cout << minDiff << '\n';
}
