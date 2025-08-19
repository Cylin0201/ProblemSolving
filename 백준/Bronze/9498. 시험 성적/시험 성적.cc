#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    if (N >= 90 && N <= 100) std::cout << 'A' << '\n';
    else if (N >= 80 && N <= 89) std::cout << 'B' << '\n';
    else if (N >= 70 && N <= 79) std::cout << 'C' << '\n';
    else if (N >= 60 && N <= 69) std::cout << 'D' << '\n';
    else std::cout << 'F' << '\n';

    return 0;
}