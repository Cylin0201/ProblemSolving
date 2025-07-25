#include <bits/stdc++.h>

int solution(std::vector<int> scoville, int K) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(scoville.begin(), scoville.end());

    int answer = 0;

    while (!pq.empty()) {
        if (pq.top() >= K) return answer;
        if (pq.size() < 2) return -1;

        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int mixed = first + second * 2;
        pq.push(mixed);
        answer++;
    }

    return -1; 
}
