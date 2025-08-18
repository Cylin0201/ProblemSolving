#include <bits/stdc++.h>

int getDistance(std::pair<int, int> p1, std::pair<int, int> p2) {
    return std::abs(p1.first - p2.first) + std::abs(p1.second - p2.second);
}

int main() {
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N;
        std::vector<std::pair<int, int>> v(N + 2);
        std::vector <bool> visited(N + 2, false);
        bool isHappy = false;

        for (int i = 0; i < N + 2; i++) {
            std::cin >> v[i].first >> v[i].second;
        }

        std::queue<std::pair<int, int>>q;
        q.push(v[0]);    //집의 좌표
        visited[0] = true;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            if (getDistance(current, v[N + 1]) <= 1000) {   //v[N + 1] 종착지 좌표
                isHappy = true;
                break;
            }

            for (int i = 1; i <= N + 1; i++) {
                if (!visited[i] && getDistance(current, v[i]) <= 1000) {
                    visited[i] = true;
                    q.push({ v[i].first, v[i].second });
                }
            }
        }
        if (isHappy) std::cout << "happy\n";
        else std::cout << "sad\n";
    }
    return 0;
}