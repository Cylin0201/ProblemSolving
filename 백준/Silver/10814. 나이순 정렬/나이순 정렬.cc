#include <bits/stdc++.h>

std::vector<std::pair<int, int>> v;
std::vector<std::string> s;

bool cmp(std::pair<int, int> p1, std::pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    int N; std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x; std::string y; std::cin >> x >> y;
        v.push_back({ x, i });
        s.push_back(y);
    }

    std::sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        std::cout << v[i].first << ' ' << s[v[i].second] << '\n';
    }
    return 0;
}