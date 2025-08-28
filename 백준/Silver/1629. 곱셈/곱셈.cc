#include <bits/stdc++.h>

int A, B, C;

long long myPow(long long a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % C;

    long long v = myPow(a, b / 2);
    if (b % 2 == 0) return v * v % C;
    else return (v * v % C) * a % C;
}
int main() {
    std::cin >> A >> B >> C;

    std::cout << myPow(A, B) <<'\n';
    return 0;
}