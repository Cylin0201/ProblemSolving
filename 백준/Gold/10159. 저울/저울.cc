#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> v;

int main() {
    cin >> N >> M;
    v.assign(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 1; i <= N; i++)
        v[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int x, y; std::cin >> x >> y;
        v[x][y] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (v[i][k] != 1e9 && v[k][j] != 1e9) v[i][j] = std::min(v[i][j], v[i][k] + v[k][j]);

    for (int i = 1; i <= N; i++) {
        int cnt = 0;

        for (int j = 1; j <= N; j++) {
            if (i != j && v[i][j] == 1e9 && v[j][i] == 1e9) cnt++;
        }
        std::cout << cnt << '\n';
    }

    return 0;
}