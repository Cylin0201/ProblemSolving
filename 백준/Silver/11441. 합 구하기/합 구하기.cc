#include <bits/stdc++.h>

int N, M;
std::vector<int> A;
std::vector<int> prefix;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    A.assign(N + 1, 0);
    prefix.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
        prefix[i] = prefix[i - 1] + A[i]; // 누적합 계산
    }

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        std::cout << prefix[y] - prefix[x - 1] << '\n';
    }

    return 0;
}