#include <bits/stdc++.h>

int main() {
    std::string input[5];
    int maxLength = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> input[i];
        maxLength = std::max((int)input[i].size(), maxLength);
    }

    int idx = 0;

    while (true) {
        for (int i = 0; i < 5; i++) {
            if (idx == maxLength) return 0;

            if (idx < input[i].size()) std::cout << input[i][idx];
            else continue;
        }
        idx++;
    }

    return 0;
}