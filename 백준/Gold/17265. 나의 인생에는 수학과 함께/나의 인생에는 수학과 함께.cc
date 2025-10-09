#include <bits/stdc++.h>

int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

int N;
std::vector<std::vector<char>> map;
std::string str;
int maxVal = -1e9, minVal = 1e9;

int compute(const std::string& str) {
    int ret = str[0] - '0';
    for (int i = 2; i < str.size(); i += 2) {
        if (str[i - 1] == '+') ret += (str[i] - '0');
        else if (str[i - 1] == '-') ret -= (str[i] - '0');
        else if (str[i - 1] == '*') ret *= (str[i] - '0');
    }

    return ret;
}

void DFS(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        int val = compute(str);
        maxVal = std::max(maxVal, val);
        minVal = std::min(minVal, val);
        return;
    }
    
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!(nx >= 0 && nx < N && ny >= 0 && ny < N))
            continue;
        str.push_back(map[nx][ny]);
        DFS(nx, ny);
        str.pop_back();
    }
}

int main() {
    std::cin >> N;
    map.assign(N, std::vector<char>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> map[i][j];

    str.push_back(map[0][0]);
    DFS(0, 0);
    std::cout << maxVal << ' ' << minVal << '\n';

    return 0;
}