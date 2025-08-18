#include <bits/stdc++.h>

int main() {
    std::vector<int> v(5); int sum = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> v[i];
        sum += v[i];
    }

    std::sort(v.begin(), v.end());

    std::cout << sum / 5 << ' ' << v[2] << '\n';

    return 0;
}