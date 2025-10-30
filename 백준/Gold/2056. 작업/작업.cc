#include <bits/stdc++.h>

int N;
std::vector<int> t;
std::vector<std::vector<int>> task;
std::vector<int> deg;
std::vector<int> dp;
int main() {    
    std::cin >> N;
    t.assign(N + 1, 0);
    dp.assign(N + 1, 0);
    deg.assign(N + 1, 0);
    task.assign(N + 1, {});

    for (int i = 1; i <= N; i++) {
        std::cin >> t[i];
        dp[i] = t[i];
        int T; std::cin >> T;
        for (int j = 0; j < T; j++) {
            int input; std::cin >> input;
            task[input].push_back(i);
            deg[i]++;
        }
    }

    std::queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : task[cur]) {
            dp[next] = std::max(dp[next], dp[cur] + t[next]);
            deg[next]--;
            if (deg[next] == 0) q.push(next);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}