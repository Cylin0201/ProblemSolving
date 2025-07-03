#include <bits/stdc++.h>

bool is_HanSoo(int n) {
    if (n < 100) return true;
    std::vector<int> v; int temp = n;
    while (temp > 0) {
        v.push_back(temp % 10);
        temp /= 10;
    }
    int d = v[1] - v[0];
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i + 1] - v[i] != d) return false;
    }
    return true;
}

int main() {
    int N; std::cin >> N;

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (is_HanSoo(i)) result++;
    }
    std::cout << result << '\n';
}