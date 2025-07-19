#include <bits/stdc++.h>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int N; std::cin >> N;
    int input;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        if (input == 0) {
            if (pq.empty()) std::cout << 0 << '\n';
            else {
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(input);
    }
}