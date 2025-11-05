#include <bits/stdc++.h>

int N, result, maxScore;
std::vector<std::vector<int>> inning; // [이닝][타자]
std::vector<int> seq(9), t(9);

int getScore(const std::vector<int>& seq) {
    int res = 0;
    int player = 0; // 현재 타자 인덱스

    for (int i = 0; i < N; i++) {
        int outCnt = 0;
        bool base[3] = { 0, 0, 0 };

        while (outCnt < 3) {
            int cur = inning[i][seq[player]];

            if (cur == 0) outCnt++;
            else if (cur == 1) { 
                if (base[2]) { res++; base[2] = 0; }
                if (base[1]) { base[2] = 1; base[1] = 0; }
                if (base[0]) { base[1] = 1; base[0] = 0; }
                base[0] = 1;
            }
            else if (cur == 2) { 
                if (base[2]) { res++; base[2] = 0; }
                if (base[1]) { res++; base[1] = 0; }
                if (base[0]) { base[2] = 1; base[0] = 0; }
                base[1] = 1;
            }
            else if (cur == 3) { 
                if (base[2]) { res++; base[2] = 0; }
                if (base[1]) { res++; base[1] = 0; }
                if (base[0]) { res++; base[0] = 0; }
                base[2] = 1;
            }
            else if (cur == 4) {
                res++;
                for (int j = 0; j < 3; j++) {
                    if (base[j]) { res++; base[j] = 0; }
                }
            }
            player = (player + 1) % 9; 
        }
    }
    return res;
}

void fillSeq(int n) {
    if (n == 3) {
        fillSeq(4);
        return;
    }
    if (n == 9) {
        maxScore = std::max(maxScore, getScore(seq));
        return;
    }
    for (int i = 1; i < 9; i++) {
        if (t[i] == -1) continue;
        seq[n] = i;
        t[i] = -1;
        fillSeq(n + 1);
        t[i] = i;
    }
}

// 메인 경기 진행
void play() {
    std::fill(t.begin(), t.end(), 0);
    seq[3] = 0; // 4번 타자는 1번 선수 고정
    t[0] = -1;
    maxScore = 0;
    fillSeq(0);
    result = maxScore;
}

int main() {
    std::cin >> N;
    inning.assign(N, std::vector<int>(9));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++)
            std::cin >> inning[i][j];
    }
    play();
    std::cout << result << '\n';
    return 0;
}
