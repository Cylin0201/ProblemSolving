#include <bits/stdc++.h>

int d(int n) {
    int temp = n;
    while (temp > 0) {
        n += temp % 10;
        temp /= 10;
    }
    return n;
}

int main() {
    std::vector<int> v(10001);
    for (int i = 0; i < v.size(); i++)
        v[i] = i;

    for (int i = 1; i <= 9999; i++) {
        if (d(i) <= 10000) v[d(i)] = 0;
    }

    for (auto elem : v) {
        if (elem != 0) std::cout << elem << '\n';
    }
}