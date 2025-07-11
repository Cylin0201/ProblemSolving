#include <iostream>

int dp[31];
int main(){
    int N; std::cin >> N;
    dp[0] = 1; dp[1] = 0; dp[2] = 3;

    for (int i = 3; i <= N; i++){
        if (i % 2 != 0) dp[i] = 0;
        else{
            for (int j = 2; j <= N; j += 2){
                if (j == 2) dp[i] = dp[i - j] * dp[2];
                else if ((i - j) >= 0) dp[i] += dp[i - j] * 2;
            }
        }
    }
    std::cout << dp[N] <<'\n';
}