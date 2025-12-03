#include <bits/stdc++.h>

using namespace std;
int res;

int main() {
    int n, k, tmp; cin >> n;

    vector<int> ps(n + 1, 0);
    vector<vector<int>> dp(4, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        ps[i] = ps[i - 1] + tmp;
    }

    cin >> k;

    //객차 순회
    for (int i = 1; i <= 3; i++) {
        for (int j = i * k; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], // j번째 객차를 안 쓰는 경우
                           dp[i - 1][j - k] + ps[j] - ps[j - k]);  // 새 기관차를 j에서 끝나는 구간으로 쓰는 경우
        }
    }

    cout << dp[3][n] << '\n';
    return 0;
}