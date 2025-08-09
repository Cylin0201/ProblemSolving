#include <bits/stdc++.h>

int main(){
    int T; std::cin >> T;
    while (T--) {
        long long result = 0;
        int N; std::cin >> N;
        std::vector<long long> v(N);
        for (int i = 0; i < N; i++)
            std::cin >> v[i];

        long long maxPrice = v[v.size() - 1];

        for (int i = v.size() - 1; i >= 0; i--) {
            if (maxPrice <= v[i]) {
                maxPrice = v[i];
            }
            else result += maxPrice - v[i];
        }

        std::cout << result << '\n';
    }
}