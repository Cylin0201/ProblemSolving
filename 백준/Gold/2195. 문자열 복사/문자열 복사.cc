#include <bits/stdc++.h>

int result;
int main() {
    std::string S, P; std::cin >> S >> P;

    for (int i = 0; i < P.size();) {
        int maxLen = 0; 
        for (int j = 0; j < S.size(); j++) {
            int idx = 0;
            while (P[idx + i] == S[idx + j]) {
                idx++;
            }
            maxLen = std::max(maxLen, idx);
        }
        i += maxLen;
        result++;
    }
    std::cout << result << '\n';

    return 0;
}