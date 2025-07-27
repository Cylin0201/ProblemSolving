#include <bits/stdc++.h>

bool cmp(std::pair<int, int> p1, std::pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    int N; std::cin >> N;
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        std::pair<int, int> input; std::cin >> input.first >> input.second;
        v.push_back(input);
    }

    std::sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        std::cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}