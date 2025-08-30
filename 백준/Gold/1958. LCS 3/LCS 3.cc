#include <bits/stdc++.h>

int main() {
    std::string s1, s2, s3; std::cin >> s1 >> s2 >> s3;
    int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();

    std::vector<std::vector<std::vector<int>>> dp(size1 + 1, std::vector<std::vector<int>>(size2 + 1, std::vector<int>(size3 + 1, 0)));

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            for (int k = 1; k <= size3; k++) {
                if ((s1[i - 1] == s2[j - 1]) && (s2[j - 1] == s3[k - 1])) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else dp[i][j][k] = std::max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }
    
    std::cout << dp[size1][size2][size3] << '\n';
   
    return 0;
}