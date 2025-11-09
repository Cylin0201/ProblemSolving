#include <bits/stdc++.h>

struct Case {
    int from, to, time;
};

int N, M;
std::vector<std::vector<int>> map;
std::vector<Case> v;

int main() {
    std::cin >> N >> M;
    map.assign(N + 1, std::vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> map[i][j];

    for (int i = 0; i < M; i++) {
        Case c; std::cin >> c.from >> c.to >> c.time;
        v.push_back(c);
    }

    for (int k = 1; k <= N; k++) 
        for (int i = 1; i <= N; i++) 
            for (int j = 1; j <= N; j++) 
                map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);

    for (const Case& c: v) {
        if (c.time >= map[c.from][c.to]) std::cout << "Enjoy other party\n";
        else std::cout << "Stay here\n";
    }

    return 0;
}