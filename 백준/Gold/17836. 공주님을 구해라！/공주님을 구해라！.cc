#include <bits/stdc++.h>
using namespace std;

struct Stat {
    int x, y, gram, t;
};

int N, M, T, res = 1e9;
int dx[] = { -1 ,1 ,0, 0 };
int dy[] = { 0 ,0 ,-1, 1 };

vector<vector<int>> m;
vector<vector<vector<bool>>> visited;

int main() {
    cin >> N >> M >> T;
    m.assign(N, vector<int>(M));
    visited.assign(N, vector<vector<bool>>(M, vector<bool>(2)));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> m[i][j];

    queue<Stat> q;
    q.push({ 0, 0, 0, 0 });
    visited[0][0][0] = true;  //[x][y][gram]

    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y, ct = q.front().t, cgram = q.front().gram;
        q.pop();

        if (cx == N - 1 && cy == M - 1) {
            res = ct;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
            int ngram;
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (cgram == 1) ngram = cgram;
            else {
                if (m[nx][ny] == 2) ngram = 1;
                else if (m[nx][ny] == 0) ngram = cgram;
                else continue; //벽일 때
            }

            if (visited[nx][ny][ngram]) continue;

            visited[nx][ny][ngram] = true;
            q.push({ nx, ny, ngram, nt });
        }
    }

    if (T >= res) cout << res << '\n';
    else cout << "Fail\n";


    return 0;
}