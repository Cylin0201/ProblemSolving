#include <bits/stdc++.h>

int main() {
    int N, H; std::cin >> N >> H;
    std::vector<int> suck(H + 1, 0), jong(H + 1, 0);
    for (int i = 0; i < N; i++) {
        int input; std::cin >> input;
        if (i % 2 == 0) suck[input]++;
        else jong[input]++;
    }
    for (int i = H - 1; i >= 1; i--) {
        suck[i] += suck[i + 1];
        jong[i] += jong[i + 1];
    }
    std::vector<int> result(H + 1, 0);
    for (int i = 1; i <= H; i++) {
        result[i] = suck[i] + jong[H - i + 1];
    }
    int minVal = *std::min_element(result.begin() + 1, result.end());
    int cnt = 0;
    for (int i = 1; i < result.size(); i++) {
        if (result[i] == minVal) cnt++;
    }

    std::cout << minVal << ' ' << cnt << '\n';

}