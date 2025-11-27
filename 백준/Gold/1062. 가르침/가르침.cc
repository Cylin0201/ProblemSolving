#include <bits/stdc++.h>
using namespace std;

bool visited[26] = { false, };
char fix[] = { 'a', 'i', 'c', 't', 'n' };
int N, M;
vector<string> str;

int result = 0;

int getCnt() {
    int s = 0;
    for (int i = 0; i < str.size(); i++) {
        bool ok = true;
        for (int j = 0; j < str[i].size(); j++) {
            if (!visited[str[i][j] - 'a']) {
                ok = false;
                break;
            }
        }
        if (ok) s++;
    }
    return s;
}

void DFS(int start, int cnt) {
    if (cnt == M) {
        result = max(result, getCnt());
        return;
    }

    for (int i = start; i < 26; i++) {
        if (visited[i]) continue;
        visited[i] = true;

        DFS(i + 1, cnt + 1);

        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        str.push_back(input.substr(4, input.size() - 8));
    }

    if (M < 5) {
        cout << 0 << "\n";
        return 0;
    }

    M -= 5;

    for (int i = 0; i < 5; i++)
        visited[fix[i] - 'a'] = true;

    DFS(0, 0);

    cout << result << "\n";
    return 0;
}
