#include <bits/stdc++.h>
using namespace std;

int N, M, sx, sy, K;
vector<vector<int>> m;
vector<int> cmd;

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 }; // 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
vector<int> dice(7); //1은 윗면, 3은 동쪽, 2는 북쪽, 4는 서쪽, 5는 남쪽, 6은 아랫면
//동쪽으로 굴리면 => dice[3] = dice[1]; dice[6] = dice[3]; dice[4] = dice[6]; dice[1] = dice[4]; 
//서쪽으로 굴리면 위의 역순

//북쪽으로 굴리면 => dice[2] = dice[1]; dice[6] = dice[2]; dice[5] = dice[6]; dice[1] = dice[5]; 
//남쪽으로 굴리면 => 위의 역순

void rotate(int& x, int& y, int c) {
    int nx = x + dx[c], ny = y + dy[c];

    if (!(nx >= 0 && nx < N && ny >= 0 && ny < M))
        return;
    
    auto temp = dice;
    if (c == 1) {
        dice[3] = temp[1]; dice[6] = temp[3]; dice[4] = temp[6]; dice[1] = temp[4];
    }
    else if (c == 2) {
        dice[1] = temp[3]; dice[3] = temp[6]; dice[6] = temp[4]; dice[4] = temp[1];
    }
    else if (c == 3) {
        dice[2] = temp[1]; dice[6] = temp[2]; dice[5] = temp[6]; dice[1] = temp[5];
    }
    else {
        dice[1] = temp[2]; dice[2] = temp[6]; dice[6] = temp[5];     dice[5] = temp[1];
    }
    x = nx; y = ny;

    if (m[nx][ny] == 0)
        m[nx][ny] = dice[6];
    else {
        dice[6] = m[nx][ny];
        m[nx][ny] = 0;
    }

    std::cout << dice[1] << '\n';
}

int main() {
    cin >> N >> M >> sx >> sy >> K;
    m.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> m[i][j];
    
    for (int i = 0; i < K; i++) {
        int c; cin >> c;
        cmd.push_back(c);
    }

    for (int i = 0; i < cmd.size(); i++) {
        rotate(sx, sy, cmd[i]);
    }

    return 0;
}