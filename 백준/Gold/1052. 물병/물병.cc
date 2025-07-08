#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    int result = 0;
    int temp = N;

    while (true) {
        int count = 0;
        int t = temp;

        // temp를 이진수로 표현했을 때 1의 개수 구하기 (병 수)
        while (t > 0) {
            if (t % 2 == 1) count++;
            t /= 2;
        }

        if (count <= K) break;

        temp += 1;     // 병 1개 추가 구매
        result += 1;
    }

    std::cout << result << '\n';
}
