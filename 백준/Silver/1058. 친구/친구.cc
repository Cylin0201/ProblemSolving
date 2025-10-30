#include <bits/stdc++.h>

int N;
std::vector<std::vector<int>> map;

int main() {
    std::cin >> N;
    map.assign(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        std::string input; std::cin >> input;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                map[i][j] = 0;
                continue;
            }
            
            if (input[j] == 'N') map[i][j] = 1e9;
            else map[i][j] = 1;
        }
    }

    //플로이드-워셜
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][k] != 1e9 && map[k][j] != 1e9 && k != j)
                map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++){
            if (i != j && map[i][j] <= 2) cnt++;
        }
        ans = std::max(ans, cnt);
    }

    std::cout << ans << '\n';
    return 0;
}