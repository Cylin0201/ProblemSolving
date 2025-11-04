#include <bits/stdc++.h>

struct Cup {
    int capacity, x;
};

Cup cups[3];
std::set<int> s;
bool visited[201][201][201]; // 상태: (A, B, C)의 물 양

void DFS(int a, int b, int c) {
    if (visited[a][b][c]) return;
    visited[a][b][c] = true;

    if (a == 0) s.insert(c);

    int cur[3] = { a, b, c };

    // 6가지 붓기 경우의 수 (i → j)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (cur[i] == 0) continue; // i가 비었으면 못 붓는다
            if (cur[j] == cups[j].capacity) continue; // j가 꽉 찼으면 못 붓는다

            int next[3] = { cur[0], cur[1], cur[2] };

            int pour = std::min(cur[i], cups[j].capacity - cur[j]);
            next[i] -= pour;
            next[j] += pour;

            DFS(next[0], next[1], next[2]);
        }
    }
}

int main() {
    std::cin >> cups[0].capacity >> cups[1].capacity >> cups[2].capacity;

    cups[0].x = cups[1].x = 0;
    cups[2].x = cups[2].capacity;

    DFS(0, 0, cups[2].capacity);

    for (int x : s)
        std::cout << x << ' ';

    return 0;
}
