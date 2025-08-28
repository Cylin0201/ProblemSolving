#include <bits/stdc++.h>

int N, M;       //M이 폐업시키지 않을 치킨집 갯수
int chickenCnt;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
int minDistance = 1e9;
std::vector<std::vector<int>> map;
std::vector<std::pair<int, int>> chicken;
std::vector<std::pair<int, int>> homePos;
std::vector<int> pos;

void calculateDistance(std::vector<int> pos) {
    //치킨집 고르기
    for (int i = 0; i < pos.size(); i++) {
        auto chickenLoc = chicken[pos[i]];
        map[chickenLoc.first][chickenLoc.second] = 2;
    }   
    int d = 0;
    // 각 집에서 치킨집까지의 최단거리 구하기
    for (int i = 0; i < homePos.size(); i++) {
        int hx = homePos[i].first, hy = homePos[i].second;
        int dist = 1e9;
        for (int j = 0; j < pos.size(); j++) {
            auto c = chicken[pos[j]];
            dist = std::min(dist, abs(hx - c.first) + abs(hy - c.second));
        }
        d += dist;
    }

    //치킨집 복원
    for (int i = 0; i < pos.size(); i++) {
        auto chickenLoc = chicken[pos[i]];
        map[chickenLoc.first][chickenLoc.second] = 0;
    }

    minDistance = std::min(minDistance, d);
}

void choosePos(int start) {
    if (M == pos.size()) {
        calculateDistance(pos);
        return ;
    }

    for (int i = start; i < chickenCnt; i++) {
        pos.push_back(i);
        choosePos(i + 1);
        pos.pop_back();
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(NULL);

    std::cin >> N >> M;
    map.assign(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 2) {
                chicken.push_back({ i, j });
                chickenCnt++;
                map[i][j] = 0;
            }
            else if (map[i][j] == 1)
                homePos.push_back({ i,j });
        }
    }

    choosePos(0);
    std::cout << minDistance << '\n';

    return 0;
}