#include <bits/stdc++.h>
int main() {
    int N; std::cin >> N;
    std::vector<int> crane(N);
    for (int i = 0; i < N; i++) std::cin >> crane[i];

    int M; std::cin >> M;
    std::vector<int> box(M);
    for (int i = 0; i < M; i++) std::cin >> box[i];

    sort(crane.rbegin(), crane.rend());
    sort(box.rbegin(), box.rend());

    if (crane[0] < box[0]) {
        std::cout << -1 << '\n';
        return 0;
    }

    int t = 0;
    std::vector<bool> visited(M, false);
    int moved = 0;

    while (moved < M) {
        int idx = 0;  // 크레인 인덱스
        for (int i = 0; i < M; i++) {
            if (idx >= N) break;

            if (!visited[i] && crane[idx] >= box[i]) {
                visited[i] = true;
                idx++;
                moved++;
            }
        }
        t++;
    }

    std::cout << t << '\n';
}