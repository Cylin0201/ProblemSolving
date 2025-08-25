#include <bits/stdc++.h>

int main() {
    int N, M; std::cin >> N >> M;
    std::vector<int> v(N), diff;
    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());

    for (int i = 0; i < N - 1; i++) {
        int d = v[i + 1] - v[i];
        if (d > 0) diff.push_back(d);
    }
    
    std::sort(diff.begin(), diff.end(), std::greater<int>());

    int result = 0;
    for (int i = M - 1; i < diff.size(); i++)
        result += diff[i];

    std::cout << result << '\n';
    return 0;   
}