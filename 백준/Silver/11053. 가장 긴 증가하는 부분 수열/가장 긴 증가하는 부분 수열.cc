#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> A(N);
    std::vector<int> dp(N, 1);

    for (int i = 0; i < N; i++) 
        std::cin >> A[i];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = *std::max_element(dp.begin(), dp.end());
    std::cout << result << std::endl;

    return 0;
}
