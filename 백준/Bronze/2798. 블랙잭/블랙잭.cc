#include <bits/stdc++.h>

int main() {
    int N, M; std::cin >> N >> M;
    std::vector<int> input(N);
    int max = 0;

    for (int i = 0; i < N; i++)
        std::cin >> input[i];

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = input[i] + input[j] + input[k];
                if (sum > max && sum <= M)
                    max = sum;

                if (sum > M) continue;
            }
        }
    }
    std::cout << max << '\n';

}