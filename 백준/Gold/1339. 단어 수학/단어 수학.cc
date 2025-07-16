#include <bits/stdc++.h>

std::vector<std::pair<char, int>> cnt(26), level(26);
std::vector<char> sorted(26);

bool cmp(char c1, char c2) {
    if (level[c1 - 'A'].second != level[c2 - 'A'].second)
        return level[c1 - 'A'].second > level[c2 - 'A'].second;
    return cnt[c1 - 'A'].second > cnt[c2 - 'A'].second;
}

int main() {
    for (int i = 0; i < 26; i++) {
        cnt[i] = { 'A' + i, 0 };
        level[i] = { 'A' + i, 0 };
        sorted[i] = 'A' + i;
    }

    int N;
    std::cin >> N;
    std::vector<std::string> v(N);
    std::vector<int> converted_v(N, 0);

    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
        for (int j = 0; j < v[i].size(); j++) {
            cnt[v[i][j] - 'A'].second++;
            level[v[i][j] - 'A'].second += std::pow(10, v[i].size() - j - 1);
        }
    }

    std::sort(sorted.begin(), sorted.end(), cmp);

    std::unordered_map<char, int> char_to_digit;
    int digit = 9;
    for (char c : sorted) {
        if (level[c - 'A'].second > 0 || cnt[c - 'A'].second > 0) {
            char_to_digit[c] = digit--;
        }
    }

    // 단어들을 숫자로 변환
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int place = v[i].size() - j - 1;
            converted_v[i] += std::pow(10, place) * char_to_digit[v[i][j]];
        }
    }

    // 총합 계산
    int sum = 0;
    for (int val : converted_v)
        sum += val;

    std::cout << sum << '\n';
}
