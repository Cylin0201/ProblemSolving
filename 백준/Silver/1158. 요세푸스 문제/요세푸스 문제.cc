#include <bits/stdc++.h>

int main() {
    int N, K; std::cin >> N >> K;
    std::queue<int> q;
    std::vector<int> result;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while (!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        result.push_back(q.front());
        q.pop();
    }

    std::cout << '<';
    for (int i = 0; i < result.size(); i++) {
        if (i != result.size() - 1) std::cout << result[i] << ", ";
        else std::cout << result[i] << ">\n";
    }

    return 0;
}
