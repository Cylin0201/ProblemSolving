#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<int> v(N), LIS(N, 1), LDS(N, 1), LBS(N, 0);

    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) LIS[i] = std::max(LIS[i], LIS[j] + 1);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (v[i] > v[j]) LDS[i] = std::max(LDS[i], LDS[j] + 1);
        }
    }

    for (int i = 0; i < N; i++) 
        LBS[i] = LIS[i] + LDS[i] - 1;

    std::cout << *std::max_element(LBS.begin(), LBS.end()) << '\n';
}