#include <bits/stdc++.h>
int N;
std::vector<int> dist;
std::vector<std::vector<std::pair<int, int>>> graph;
int result = 0;

int DFS(int node, int parent, int d) {
    int max1 = 0, max2 = 0; // 가장 긴 거리와 두 번째 긴 거리

    for (auto& next : graph[node]) {
        int child = next.first;
        int w = next.second;
        if (child == parent) continue; // 부모로 역방향 방지

        int childDist = DFS(child, node, d + w) - d; // 현재 노드로부터의 거리
        if (childDist > max1) {
            max2 = max1;
            max1 = childDist;
        }
        else if (childDist > max2) {
            max2 = childDist;
        }
    }

    result = std::max(result, max1 + max2); // 지름 갱신
    return d + max1; // 부모 방향으로는 가장 긴 거리만 반환
}

int main() {
    std::cin >> N;
    graph.assign(N + 1, {});
    dist.assign(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        graph[x].push_back({ y, z });
        graph[y].push_back({ x, z }); // 양방향
    }

    DFS(1, -1, 0);

    std::cout << result << '\n';
    return 0;
}
