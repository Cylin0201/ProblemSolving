#include <bits/stdc++.h>
std::vector<long long> result;

void generate_decreasing_numbers(long long num, int last_digit) {
    result.push_back(num); 

    for (int next_digit = 0; next_digit < last_digit; next_digit++) {
        generate_decreasing_numbers(num * 10 + next_digit, next_digit);
    }
}

int main() {
    int N; std::cin >> N;

    for (int i = 0; i <= 9; i++) {
        generate_decreasing_numbers(i, i);
    }

    std::sort(result.begin(), result.end());

    if (N >= result.size()) std::cout << -1 << '\n';
    else std::cout << result[N] << '\n';
    

    return 0;
}