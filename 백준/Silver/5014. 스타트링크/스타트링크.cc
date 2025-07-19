#include <bits/stdc++.h>

int F, S, G, U, D;
std::vector<int> building;

bool BFS(int start) {
    std::queue<int> q;
    q.push(start);
    building[start] = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == G) return true;

        int nextUp = current + U;
        if (nextUp <= F && building[nextUp] == -1) {
            building[nextUp] = building[current] + 1;
            q.push(nextUp);
        }
        int nextDown = current - D;
        if (nextDown >= 1 && building[nextDown] == -1) {
            building[nextDown] = building[current] + 1;
            q.push(nextDown);
        }
    }
    return false;
}

int main() {
    std::cin >> F >> S >> G >> U >> D;
    building.assign(F + 1, -1);

    if (BFS(S)) std::cout << building[G] << '\n';
    else std::cout << "use the stairs\n";
    
    return 0;
}