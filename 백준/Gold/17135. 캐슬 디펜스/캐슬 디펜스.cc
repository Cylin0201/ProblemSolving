#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, -1, 0 }; // 좌, 상, 우 순서
int dy[] = { -1, 0, 1 };

int N, M, K, result;
vector<vector<int>> origin;

// 적이 남았는지 체크
bool checkEnemies(vector<vector<int>>& mp) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (mp[i][j] == 1) return false;
    return true;
}

// BFS로 가장 가까운 적 탐색
pair<int, int> attackTarget(vector<vector<int>>& mp, int ax, int ay) {

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    int sx = ax - 1;
    int sy = ay;

    if (sx < 0) return { -1, -1 };

    q.push({ sx, sy });
    visited[sx][sy] = true;

    int dist = 1;

    while (!q.empty() && dist <= K) {

        int qs = q.size();
        while (qs--) {
            auto [x, y] = q.front(); q.pop();

            if (mp[x][y] == 1) return { x, y };

            for (int d = 0; d < 3; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true; 
                q.push({ nx, ny });
            }
        }
        dist++;
    }

    return { -1, -1 };
}

void simulate(vector<int> pos) {
    vector<vector<int>> mp = origin;
    int cnt = 0;

    while (true) {

        if (checkEnemies(mp)) {
            result = max(result, cnt);
            return;
        }

        set<pair<int, int>> targets;

        // 1. 궁수 공격
        for (int j = 0; j < M; j++) {
            if (pos[j] != 2) continue;

            auto t = attackTarget(mp, N, j);
            if (t.first != -1) targets.insert(t);
        }

        // 2. 적 제거
        for (auto& t : targets) {
            auto [x, y] = t;
            if (mp[x][y] == 1) {
                mp[x][y] = 0;
                cnt++;
            }
        }

        // 3. 적 이동
        for (int i = N - 1; i > 0; i--)
            for (int j = 0; j < M; j++)
                mp[i][j] = mp[i - 1][j];

        for (int j = 0; j < M; j++)
            mp[0][j] = 0;
    }
}

void DFS(vector<int> pos, int idx, int cnt) {

    if (cnt == 3) {
        simulate(pos);
        return;
    }

    for (int i = idx; i < M; i++) {
        if (pos[i] == 2) continue;

        pos[i] = 2;
        DFS(pos, i + 1, cnt + 1);
        pos[i] = 0;
    }
}

int main() {
    cin >> N >> M >> K;

    origin.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> origin[i][j];

    vector<int> pos(M, 0);
    DFS(pos, 0, 0);

    cout << result << "\n";
}
