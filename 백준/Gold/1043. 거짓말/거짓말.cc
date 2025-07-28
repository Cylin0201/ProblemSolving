#include <bits/stdc++.h>

int N, M; 
int n1; std::vector<bool> v;
std::vector<std::vector<int>> p;

int main() {
    std::cin >> N >> M;
    std::cin >> n1;
    p.assign(M, std::vector<int>());
    if (n1 > 0) {
        v.assign(N + 1, false);
        for (int i = 0; i < n1; i++) {
            int input; std::cin >> input;
            v[input] = true;
        }
    }

    for (int i = 0; i < M; i++) {
        int input; std::cin >> input;
        p[i].assign(input, 0);
        for (int j = 0; j < input; j++)
            std::cin >> p[i][j];
    }

    if (n1 == 0) {
        std::cout << M << '\n';
        return 0;
    }

    for (int r = 0; r < M; r++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < p[i].size(); j++) {
                if (v[p[i][j]]) {
                    for (int k = 0; k < p[i].size(); k++)
                        v[p[i][k]] = true;
                    break;
                }
            }
        }
    }

    int result = M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < p[i].size(); j++) {
            if (v[p[i][j]]) {
                result--;
                break;
            }
        }
    }

    std::cout << result << '\n';
    return 0;

}