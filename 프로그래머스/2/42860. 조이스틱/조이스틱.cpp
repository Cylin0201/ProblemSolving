#include <bits/stdc++.h>

int UpDown(char c){
    c -= 'A';
    return (26 - c < c) ? 26 - c : c;
}

int solution(std::string name) {
    int result = 0;
    int len = name.size();

    for (int i = 0 ; i < len; i++){
        result += UpDown(name[i]);
    }

    int move = len - 1;

    for (int i = 0; i < len; i++) {
        int next = i + 1;

        // 연속된 'A' 찾기
        while (next < len && name[next] == 'A') next++;

        // 두 가지 경우 중 최소 이동 선택
        int leftThenRight = i * 2 + len - next;
        int rightThenLeft = (len - next) * 2 + i;
        move = std::min(move, std::min(leftThenRight, rightThenLeft));
    }

    result += move;
    return result;
}