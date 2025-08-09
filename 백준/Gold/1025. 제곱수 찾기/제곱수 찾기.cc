#include <bits/stdc++.h>

int N, M;
std::vector<std::string> v;
long long result = -1;

bool isSquare(long long x) {
    long long r = sqrt(x);
    return r * r == x;
}

int main() {
    std::cin >> N >> M;
    v.assign(N, std::string());
    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dx = -N; dx <= N; dx++) {
                for (int dy = -M; dy <= M; dy++) {
                    if (dx == 0 && dy == 0) continue; // 이동 안 하는 경우 제외

                    int x = i, y = j;
                    long long num = 0;
                    while (x >= 0 && x < N && y >= 0 && y < M) {
                        num = num * 10 + (v[x][y] - '0');
                        if (isSquare(num)) result = std::max(result, num);

                        x += dx;
                        y += dy;
                    }
                }
            }
        }
    }

    std::cout << result << "\n";
}