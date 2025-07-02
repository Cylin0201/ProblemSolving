#include <bits/stdc++.h>

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N; std::cin >> N;
    std::vector<int> A(N), B(N);

    for (int i = 0; i < N; i++)
        std::cin >> A[i];
    for (int i = 0; i < N; i++)
        std::cin >> B[i];

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), cmp);
    
    int result = 0;
    for (int i = 0; i < N; i++)
        result += A[i] * B[i];

    std::cout << result << '\n';
}