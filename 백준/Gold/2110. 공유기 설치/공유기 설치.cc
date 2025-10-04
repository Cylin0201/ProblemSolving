#include <bits/stdc++.h>

int N, C;
std::vector<int> x;

bool possible(int dist) {
    int cnt = 1;        //가장 먼저 집에는 무조건 공유기 설치하기
    int prev = x[0];

    for (int i = 1; i < N; i++) {
        if (x[i] - prev >= dist) {
            cnt++;
            prev = x[i];
        }
    }

    if (cnt >= C) return true;
    return false;
}

int main() {
    std::cin >> N >> C;
    x.assign(N, 0);
    for (int i = 0; i < N; i++)
        std::cin >> x[i];
    std::sort(x.begin(), x.end());

    int low = 1, high = x[N - 1] - x[0];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(mid)) {
            result = std::max(result, mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }

    std::cout << result << '\n';
    return 0;
}