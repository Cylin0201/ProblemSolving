#include <bits/stdc++.h>

int N;
std::vector<std::pair<int, int>> wires;
std::vector<int> dp;

int main() {
    std::cin >> N;
    wires.assign(N + 1, { 0, 0 });
    dp.assign(N + 1, 0);

    for (int i = 1; i <= N; i++)
        std::cin >> wires[i].first >> wires[i].second;

    std::sort(wires.begin(), wires.end());

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (wires[i].second > wires[j].second)
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }
    int len = *std::max_element(dp.begin(), dp.end());
    std::cout << N - len << '\n';
}