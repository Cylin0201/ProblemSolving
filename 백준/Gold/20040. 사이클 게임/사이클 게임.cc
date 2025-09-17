#include <bits/stdc++.h>

std::vector<int> parent;

int getParent(int x) {
    if (x == parent[x]) return parent[x];
    return parent[x] = getParent(parent[x]);
}

bool isUnion(int a, int b) {
    return getParent(a) == getParent(b);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    int n, m; std::cin >> n >> m;
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        int a, b; std::cin >> a >> b;
        v.push_back({ a, b });
    }


    int t;
    for (t = 0; t < m; t++) {
        if (!isUnion(v[t].first, v[t].second))
            unionParent(v[t].first, v[t].second);
        else {
            std::cout << t + 1 << '\n';
            return 0;
        }
    }

    std::cout << 0 << '\n';
    return 0;   
}