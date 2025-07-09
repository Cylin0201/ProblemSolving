#include <bits/stdc++.h>

int main() {
    int N, K; std::cin >> N >> K;
    std::vector<int> students(N);

    for (int i = 0; i < N; i++) 
        std::cin >> students[i];

    sort(students.begin(), students.end());

    std::vector<int> diffs;
    for (int i = 1; i < N; i++) {
        diffs.push_back(students[i] - students[i - 1]);
    }

    sort(diffs.begin(), diffs.end(), std::greater<int>());
    int answer = 0;
    for (int i = K - 1; i < diffs.size(); i++) {
        answer += diffs[i];
    }

    std::cout << answer << '\n';
    return 0;
}