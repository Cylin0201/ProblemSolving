#include <bits/stdc++.h>
using namespace std;

int dx[4][2] = { {0, 1}, {0, 1}, {0, -1}, {0, -1} };
int dy[4][2] = { {1, 0}, {-1, 0}, {1, 0}, {-1, 0} };

int N, M;
vector<vector<int>> woods;
vector<vector<bool>> visited;
int result;

void DFS(int x, int y, int score) {
    if (y == M) {
        y = 0;
        x++;
    }

    if (x == N) {
        result = max(result, score);
        return;
    }

    if (!visited[x][y]) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int temp = score + 2 * woods[x][y];
            bool ok = true;
            int px[2], py[2];

            for (int j = 0; j < 2; j++) {
                px[j] = x + dx[i][j];
                py[j] = y + dy[i][j];

                if (px[j] < 0 || px[j] >= N || py[j] < 0 || py[j] >= M || visited[px[j]][py[j]]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                for (int j = 0; j < 2; j++) {
                    visited[px[j]][py[j]] = true;
                    temp += woods[px[j]][py[j]];
                }

                DFS(x, y + 1, temp);

                for (int j = 0; j < 2; j++)
                    visited[px[j]][py[j]] = false;
            }
        }

        visited[x][y] = false;
    }

    DFS(x, y + 1, score);
}

int main() {
    cin >> N >> M;
    woods.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> woods[i][j];

    if (N == 1 || M == 1)
        result = 0;
    else
        DFS(0, 0, 0);

    cout << result << '\n';
    return 0;
}
