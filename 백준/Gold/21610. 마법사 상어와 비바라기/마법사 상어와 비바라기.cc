#include <bits/stdc++.h>

int N, M;
std::vector<std::vector<int>> A;
std::vector<std::vector<int>> Cloud;
std::vector<std::pair<int, int>> cmd;

int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

std::vector<std::pair<int, int>> v;   //초기 구름 위치

void command(std::pair<int, int> p, int d, int s) {     //1, 2번
    int x = p.first, y = p.second;
    while (s--) {
        x += dx[d]; y += dy[d];
        if (x < 1) x = N;
        if (x > N) x = 1;
        if (y < 1) y = N;
        if (y > N) y = 1;
    }
    Cloud[x][y] = 1;
    A[x][y] += 1;
}

void copy() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (Cloud[i][j] == 1) {     // 구름이 있는 칸
                for (int dir : {2, 4, 6, 8}) {
                    int nx = i + dx[dir], ny = j + dy[dir];
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && A[nx][ny] > 0)
                        A[i][j]++;
                }
            }
        }
    }
}

void makeCloud() {
    std::vector<std::pair<int, int>> newCloud;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i][j] >= 2 && Cloud[i][j] != 1) {  // 이번 턴 구름 없던 칸만
                A[i][j] -= 2;
                newCloud.push_back({ i, j });
            }
        }
    }

    // Cloud 배열 초기화 후 새 구름만 표시
    Cloud.assign(N + 1, std::vector<int>(N + 1, 0));
    v = newCloud;
    for (auto p : v)
        Cloud[p.first][p.second] = 1;
}

int main() {
    std::cin >> N >> M;
    A.assign(N + 1, std::vector<int>(N + 1, 0));
    Cloud.assign(N + 1, std::vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> A[i][j];

    for (int i = 0; i < M; i++) {
        int d, s; std::cin >> d >> s;
        cmd.push_back({ d, s });
    }

    v = { { N, 1 }, { N, 2 }, { N - 1, 1 }, { N - 1, 2 } };
    for (auto p : v)
        Cloud[p.first][p.second] = 1;

    for (int j = 0; j < cmd.size(); j++) {
        Cloud.assign(N + 1, std::vector<int>(N + 1, 0));
        for (int i = 0; i < v.size(); i++) {
            command(v[i], cmd[j].first, cmd[j].second);
        }
        copy();
        v.clear();
        makeCloud();
    }

    int sum = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            sum += A[i][j];

    std::cout << sum << '\n';
    return 0;
}
