#include <bits/stdc++.h>

int N, M;
std::vector<int> parent;
int ans;

int getParent(int x) {
    if (x == parent[x]) return parent[x];
    return parent[x] = getParent(parent[x]);
}

bool isUnion(int a, int b) {
    return getParent(a) == getParent(b);
}

void unionParent(int a, int b) {
    a = getParent(a); b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
     std::cin >> N >> M;
     parent.assign(N + 1, 0);
     std::vector<int> v(N, 0);
     for (int i = 1; i <= N; i++)
         parent[i] = i;

     for (int i = 0; i < M; i++) {
         int x, y; std::cin >> x >> y;
         unionParent(x, y);
     }
     for (int i = 0; i < N; i++)
         std::cin >> v[i];

     for (int i = 0; i < N - 1; i++) {
         if (!isUnion(v[i], v[i + 1])) ans++;
     }
     std::cout << ans << '\n';

    return 0;
}