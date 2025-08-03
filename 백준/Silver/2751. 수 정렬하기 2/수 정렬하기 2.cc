#include <bits/stdc++.h>

int main() {
    int N; std::cin >> N;
    std::priority_queue<int> q;
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        q.push(-x);
    }

    while (!q.empty()) {
        std::cout << -q.top() << '\n';
        q.pop();
    }
}