#include <bits/stdc++.h>
int N, M;
int map[101];
int visited[101];

int bfs() {
    std::queue<std::pair<int, int>> q; // (현재 칸, 주사위 굴린 횟수)
    q.push({ 1, 0 });
    visited[1] = 1;

    while (!q.empty()) {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (curr == 100) return cnt;

        for (int dice = 1; dice <= 6; dice++) {
            int next = curr + dice;
            if (next > 100) continue;

            next = map[next];
            if (!visited[next]) {
                visited[next] = 1;
                q.push({ next, cnt + 1 });
            }
        }
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 1; i <= 100; i++)
        map[i] = i;

    for (int i = 0; i < N + M; i++) {
        int x, y; std::cin >> x >> y;
        map[x] = y;
    }
    std::cout << bfs() << '\n';
}