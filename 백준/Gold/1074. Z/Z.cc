#include <bits/stdc++.h>

int solve(int n, int r, int c) {
    if (n == 0) return 0;

    int half = std::pow(2, n - 1);
    int area = half * half;  // 각 사분면 크기

    if (r < half && c < half) // 1사분면
        return solve(n - 1, r, c);
    else if (r < half && c >= half) // 2사분면
        return area + solve(n - 1, r, c - half);
    else if (r >= half && c < half) // 3사분면
        return 2 * area + solve(n - 1, r - half, c);
    else // 4사분면
        return 3 * area + solve(n - 1, r - half, c - half);
}

int main() {
    int N, r, c;
    std::cin >> N >> r >> c;
    std::cout << solve(N, r, c) << '\n';
    return 0;
}
