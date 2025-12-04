#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> v;

bool check(const string& str) {
    int mCnt = 0, jCnt = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            mCnt++;
        else jCnt++;
    }
    return (jCnt >= 2 && mCnt >= 1);
}

void DFS(string str, int idx) {
    if (str.length() == L) {
        if (check(str)) cout << str << '\n';
        return;
    }
    
    for (int i = idx; i < C; i++) {
        str.push_back(v[i]);
        DFS(str, i + 1);
        str.pop_back();
    }
}

int main() {
    cin >> L >> C;
    v.assign(C, 0);

    for (int i = 0; i < C; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    string str = "";
    DFS(str, 0);

    return 0;
}