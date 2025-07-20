#include <bits/stdc++.h>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    while (m > 0) {
        std::sort(a.begin(), a.end());
        a[0] = a[1] = a[0] + a[1];
        m--;
    }

    long long sum = 0;
    for (auto elem : a)
        sum += elem;

    std::cout << sum << '\n';
}