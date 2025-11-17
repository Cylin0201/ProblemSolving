#include <bits/stdc++.h>
using namespace std;

struct Trio {
    int a, b, k;
};
int N, M;
vector<int> v, tmp;
vector<Trio> cmd;

int main() {
    cin >> N >> M;
    v.assign(N + 1, 0);
    tmp.assign(N + 2, 0);

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = 0; i < M; i++) {
        int a, b, k; cin >> a >> b >> k;
        cmd.push_back({ a, b, k });
    }
    
    for (const auto& trio : cmd) {
        tmp[trio.a] += trio.k;
        tmp[trio.b + 1] -= trio.k;
    }

    for (int i = 1; i < N; i++)
        tmp[i + 1] += tmp[i];
    
    for (int i = 1; i <= N; i++) {
        cout << v[i] + tmp[i] << ' ';
    }

    return 0;
}