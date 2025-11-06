#include <bits/stdc++.h>

long long N, M;
std::vector<long long> t;

bool canProcess(long long mid) {
    long long cnt = 0;
    for (long long time : t) {
        cnt += mid / time;
        if (cnt >= M) return true;
    }
    return cnt >= M;
}

int main() {
    std::cin >> N >> M;
    t.resize(N);
    for (int i = 0; i < N; i++)
        std::cin >> t[i];

    long long low = 1;
    long long high = *max_element(t.begin(), t.end()) * M;
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canProcess(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    std::cout << ans << '\n';
    return 0;
}