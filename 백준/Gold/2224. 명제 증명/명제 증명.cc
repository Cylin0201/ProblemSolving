#include <bits/stdc++.h>
#define LEN 52

int N;
std::vector<std::vector<int>> v(LEN, std::vector<int>(LEN, 1e9));
std::vector<std::pair<int, int>> res;

int toInt(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch - 'A';
    else if (ch >= 'a' && ch <= 'z') return ch - 'a' + 26;
    else return -1;
}

char toChar(int a) {
    if (a >= 0 && a <= 25) return a + 'A';
    else if (a >= 26 && a <= 51) return a + 'a' - 26;
    else return -1;
}

bool cmp(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    std::cin >> N;
    for (int i = 0; i < LEN; i++)
        v[i][i] = 0;

    for (int i = 0; i < N; i++) {
        char c1, c2; std::string t;  std::cin >> c1 >> t >> c2;
        v[toInt(c1)][toInt(c2)] = 1;
    }

    for (int k = 0; k < LEN; k++) {
        for (int i = 0; i < LEN; i++) {
            for (int j = 0; j < LEN; j++) {
                v[i][j] = std::min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (i != j && v[i][j] < 1e9) res.push_back({i, j});
        }
    }

    std::sort(res.begin(), res.end(), cmp);

    std::cout << res.size() << '\n';
    for (auto elem : res) {
        std::cout << toChar(elem.first) << " => " << toChar(elem.second) << '\n';
    }

    return 0;
}