#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, b, d;

    bool operator< (const Node& node) const{
        return node.d < d;
    }
};

int N, M;
vector<char> gdr;
vector<int> parent;

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

bool isUnion(int a, int b) {
    return getParent(a) == getParent(b);
}

void unionParent(int a, int b) {
    a = getParent(a); b = getParent(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}


int main() {
    cin >> N >> M;
    gdr.assign(N + 1, 0);
    parent.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> gdr[i];
    
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    priority_queue<Node> pq;
    for (int i = 0; i < M; i++) {
        int a, b, d; cin >> a >> b >> d;
        pq.push({ a, b, d });
    }

    int result = 0, cnt = 0;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (isUnion(cur.a, cur.b) || gdr[cur.a] == gdr[cur.b])
            continue;
        unionParent(cur.a, cur.b);
        result += cur.d;
        cnt++;
    }

    if (cnt != N - 1) result = -1;

    cout << result << '\n';

    return 0;
}