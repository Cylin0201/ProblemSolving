#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::vector<long long> v(N);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    std::sort(v.begin(), v.end());

    int start = 0, end = N - 1;
    std::pair<int, int> result;
    long long sum = 2000000000;

    while (start < end) {
        int temp = v[start] + v[end];
        if (abs(temp) < sum) {
            sum = abs(temp);
            result.first = v[start];
            result.second = v[end];
        }
        if (temp > 0) end--;
        else if (temp < 0) start++;
        else break; //0이면 멈추기
    }
    std::cout << result.first << ' ' << result.second << '\n';

}