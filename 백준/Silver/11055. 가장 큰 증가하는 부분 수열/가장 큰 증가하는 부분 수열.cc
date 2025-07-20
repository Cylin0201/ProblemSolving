#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> A(N), dp(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    for (int i = 0; i < N; i++) {
        dp[i] = A[i];
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = std::max(dp[i], dp[j] + A[i]);
            }
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
}
