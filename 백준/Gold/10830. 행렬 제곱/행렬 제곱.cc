#include <bits/stdc++.h>

int N;
long long B;

std::vector<std::vector<long long>> Multiply(const std::vector<std::vector<long long>>& a, const std::vector<std::vector<long long>>& b) {
    std::vector<std::vector<long long>> res(N, std::vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= 1000; // 1000으로 나눔
            }
        }
    }
    return res;
}

// 행렬 제곱 (분할 정복)
std::vector<std::vector<long long>> MatrixPow(const std::vector<std::vector<long long>>& v, long long n) {
    if (n == 1) {
        std::vector<std::vector<long long>> base = v;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                base[i][j] %= 1000;
        return base;
    }

    std::vector<std::vector<long long>> temp = MatrixPow(v, n / 2);
    if (n % 2 == 0)
        return Multiply(temp, temp);
    else
        return Multiply(Multiply(temp, temp), v);
}


int main() {
    std::cin >> N >> B;
    std::vector<std::vector<long long>> v(N, std::vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> v[i][j];
        }
    }

    std::vector<std::vector<long long>> result = MatrixPow(v, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << result[i][j] % 1000 << ' ';
        }
        std::cout << '\n';
    }
}