#include <bits/stdc++.h>

int main() {
    int N, M; std::cin >> N >> M;
    std::vector<int> v(N);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    std::sort(v.begin(), v.end(), std::greater<int>());

    std::cout << v[M - 1] << '\n';

    return 0;
}