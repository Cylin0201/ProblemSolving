    #include <bits/stdc++.h>

    int N, M;
    std::vector<std::vector<int>> graph;
    int dx[4] = { -1, 0, 1, 0 };        //북:0, 동:1, 남:2, 서:3
    int dy[4] = { 0, 1, 0, -1 };
    int cnt;

    void DFS(int x, int y, int dir) {
        if (graph[x][y] == 0) {
            graph[x][y] = 2;
            cnt++;
        }

        for (int i = 0; i < 4; i++) {
            int next_dir = (dir + 3 - i) % 4;
            int nx = x + dx[next_dir], ny = y + dy[next_dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && graph[nx][ny] == 0) {
                DFS(nx, ny, next_dir);
                return;
            }
        }

        int back_dir = (dir + 2) % 4;
        int bx = x + dx[back_dir];
        int by = y + dy[back_dir];

        if (bx >= 0 && bx < N && by >= 0 && by < M && graph[bx][by] != 1) {
            DFS(bx, by, dir);
        }
    }

    int main() {
        std::cin >> N >> M;
        int x, y, dir; std::cin >> x >> y >> dir;
        graph.assign(N, std::vector<int>(M));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                std::cin >> graph[i][j];

        DFS(x, y, dir);

        std::cout << cnt << '\n';
        return 0;
    }
