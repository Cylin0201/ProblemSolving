#include <bits/stdc++.h>

int N;
std::vector<int> heights;
std::vector<long double> gradients;
long double getGradient(int a, int b) {
    long double w = b - a, h = heights[b] - heights[a];

    return h / w;
}

int main() {
    std::cin >> N;
    heights.assign(N + 1, 0);

    for (int i = 1; i <= N; i++)
        std::cin >> heights[i];

    int maxCnt = 0;

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        long double maxGrad = -1e18;
        for (int j = i + 1; j <= N; j++) {
            long double g = getGradient(i, j);
            if (g > maxGrad) {
                maxGrad = g;
                cnt++;
            }
        }

        long double minGrad = 1e18;
        for (int j = i - 1; j >= 1; j--) {
            long double g = getGradient(i, j);
            if (g < minGrad) {
                minGrad = g;
                cnt++;
            }
        }
        maxCnt = std::max(maxCnt, cnt);
    }

    std::cout << maxCnt << '\n';
    return 0;
}