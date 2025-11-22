#include <bits/stdc++.h>
using namespace std;

int N, M;
int result;
vector<int> v;

int getParent(int x) {
    if (x == v[x]) return x;
    return v[x] = getParent(v[x]);
}

bool isUnion(int a, int b){
    return getParent(a) == getParent(b);
}

void unionParent(int a, int b) {
    a = getParent(a); b = getParent(b);

    if (a < b) v[b] = a;
    else v[a] = b;
}


int main() {
    int T; cin >> T;
    while (T-- > 0) {
        cin >> N >> M;
        result = 0;
        v.assign(N + 1, 0);

        for (int i = 1; i <= N; i++)
            v[i] = i;

        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            if (isUnion(a, b)) continue;
            unionParent(a, b);
            result++;
        }

        cout << result << '\n';

    }
    return 0;
}