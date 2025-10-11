#include <bits/stdc++.h>

int H, W; 
std::vector<std::vector<int>> map;

int main() {
    std::cin >> H >> W;
    map.assign(H, std::vector<int>(W, 0));

    for (int i = 0; i < W; i++) {
        int h; std::cin >> h;
        for (int j = 1; j <= h; j++) {
            map[H - j][i] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        bool s = false;
        int temp = 0;
        for (int j = 0; j < W; j++) {
            if (map[i][j] == 1 && !s) s = true; 
            else if (map[i][j] == 1 && s) {
                cnt += temp;
                temp = 0;
            }
            else if (map[i][j] == 0 && s) temp++;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}