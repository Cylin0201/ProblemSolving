#include <bits/stdc++.h>
int N;

int main() {
    std::cin >> N;
    std::vector<std::pair<int, int>> lessons(N);
    for (int i = 0; i < N; i++)
        std::cin >> lessons[i].first >> lessons[i].second;

    // 시작 시간 기준 정렬
    std::sort(lessons.begin(), lessons.end());

    // 종료 시간 최소 힙
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    pq.push(lessons[0].second);  // 첫 수업의 끝나는 시간

    for (int i = 1; i < N; i++) {
        int start = lessons[i].first;
        int end = lessons[i].second;

        // 가장 빨리 끝나는 수업이 현재 수업보다 먼저 끝났으면 같은 강의실 재사용
        if (pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);  // 새로운 수업 추가
    }

    std::cout << pq.size() << '\n';  // 필요한 최소 강의실 수
}
