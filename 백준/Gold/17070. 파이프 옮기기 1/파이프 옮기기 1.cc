#include <bits/stdc++.h>

int N, cnt = 0;
std::vector<std::vector<int>> graph;

// 방향: 0 - 가로, 1 - 세로, 2 - 대각선
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

void DFS(int x, int y, int dir) {
    if (x == N - 1 && y == N - 1) {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        // 방향 제한: 가로(0) → 가로(0), 대각선(2)만 가능
        //          세로(1) → 세로(1), 대각선(2)만 가능
        if (dir == 0 && i == 1) continue; // 가로일 땐 세로 이동 불가
        if (dir == 1 && i == 0) continue; // 세로일 땐 가로 이동 불가

        int nx = x + dx[i], ny = y + dy[i];

        // 범위 확인
        if (nx >= N || ny >= N) continue;

        // 벽 확인
        if (graph[nx][ny] == 1) continue;

        // 대각선 이동 시 추가 확인
        if (i == 2 && (graph[x + 1][y] == 1 || graph[x][y + 1] == 1)) continue;

        DFS(nx, ny, i);
    }
}

int main() {
    std::cin >> N;
    graph.assign(N, std::vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> graph[i][j];

    // 파이프 시작 위치는 (0,0)-(0,1), 가로 방향
    if (graph[0][0] == 0 && graph[0][1] == 0)
        DFS(0, 1, 0);

    std::cout << cnt << '\n';
    return 0;
}
