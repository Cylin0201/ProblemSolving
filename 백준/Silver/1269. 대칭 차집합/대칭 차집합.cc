#include <bits/stdc++.h>

int main() {
    int N, M; std::cin >> N >> M;
    std::unordered_map<int, int> um;
    for (int i = 0; i < N + M; i++) {
        int input; std::cin >> input;
        um[input]++;
    }
    int result = 0;
    for (auto elem : um) {
        if (elem.second == 1) result++;
    }

    std::cout << result << '\n';

    return 0;
}