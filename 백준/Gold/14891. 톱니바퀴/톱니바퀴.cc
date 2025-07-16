#include <bits/stdc++.h>
#define CW 1
#define ACW -1

std::vector<std::deque<int>> wheels(5, std::deque<int>());
int rotate[5]; // 1~4번 톱니바퀴의 회전 방향 저장

void matchRightWheels(int leftWheel, int dir) {
    if (leftWheel >= 4) return;

    int current = leftWheel + 1;
    if (wheels[leftWheel][2] != wheels[current][6]) {
        rotate[current] = -dir;
        matchRightWheels(current, -dir);
    }
}

void matchLeftWheels(int rightWheel, int dir) {
    if (rightWheel <= 1) return;

    int current = rightWheel - 1;
    if (wheels[rightWheel][6] != wheels[current][2]) {
        rotate[current] = -dir;
        matchLeftWheels(current, -dir);
    }
}

void rollWheels(int wheel_num, int dir) {
    std::fill(rotate, rotate + 5, 0);
    rotate[wheel_num] = dir;

    matchRightWheels(wheel_num, dir);
    matchLeftWheels(wheel_num, dir);

    // 회전 실행
    for (int i = 1; i <= 4; i++) {
        if (rotate[i] == CW) {
            wheels[i].push_front(wheels[i].back());
            wheels[i].pop_back();
        }
        else if (rotate[i] == ACW) {
            wheels[i].push_back(wheels[i].front());
            wheels[i].pop_front();
        }
    }
}


int main() {
    for (int i = 1; i <= 4; i++) {   //N극은 0, S극은 1
        std::string input; std::cin >> input;
        for (int j = 0; j < input.size(); j++)
            wheels[i].push_back(input[j] - '0');
    }
    int N; std::cin >> N;
    for (int i = 0; i < N; i++) {
        int wheel_num, dir; std::cin >> wheel_num >> dir;   //방향이 1이면 시계 방향, -1이면 반시계 방향
        rollWheels(wheel_num, dir);             //회전했을 때, 옆에 있는게 같은 극이면 회전X, 다른 극이면 같은 방향으로 회전O
    }

    int result = 0;
    for (int i = 1; i <= 4; i++) {
        if (wheels[i][0] == 1) result += std::pow(2, i - 1);
    }
    std::cout << result << '\n';
}