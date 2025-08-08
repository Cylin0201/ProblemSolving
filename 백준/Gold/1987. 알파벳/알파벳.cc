#include <bits/stdc++.h>

int r, c;
std::vector<std::vector<char>> v;
std::vector<bool> visited;
int result = 1;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void DFS(int x, int y, int depth) {
    if (visited[v[x][y] - 'A']) {
        result = std::max(result, depth);
        return;
    }
    visited[v[x][y] - 'A'] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            DFS(nx, ny, depth + 1);
        }
    }
    visited[v[x][y] - 'A'] = false;
}


int main() {
    std::cin >> r >> c;
    v.assign(r, std::vector<char>(c));
    visited.assign('Z' - 'A' + 1, false);

    for (int i = 0; i < r; i++) {
        std::string input; std::cin >> input;
        for (int j = 0; j < c; j++) {
            v[i][j] = input[j];
        }
    }

    DFS(0, 0, 0);

    std::cout << result <<'\n';

    return 0;
}