#include <bits/stdc++.h>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(NULL);

    int N; std::cin >> N;
    std::vector<int> v(N * N);
    for (int i = 0; i < N * N; i++)
        std::cin >> v[i];

    std::sort(v.begin(), v.end(), std::greater<int>());

    std::cout << v[N - 1] << '\n';

    return 0;
}