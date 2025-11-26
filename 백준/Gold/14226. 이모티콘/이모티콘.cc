#include <bits/stdc++.h>
using namespace std;

int S;
vector<vector<bool>> visited;

pair<int, int> copyEmo(int clip, int display) {
    return { display, display };
}

pair<int, int> pasteEmo(int clip, int display) {
    return { clip, display + clip };
}

pair<int, int> deleteEmo(int clip, int display) {
    return { clip, display - 1 };
}

int main() {
    cin >> S;
    visited.assign(2001, vector<bool>(2001, false));

    queue<pair<pair<int, int>, int>> q;
    q.push({ {0, 1}, 0 });
    visited[1][0] = true;

    int result = 1e9;

    while (!q.empty()) {
        pair<int, int> cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        int clip = cur.first;
        int display = cur.second;

        if (display == S) {
            result = min(result, cost);
            continue;
        }

        // 1. copy
        {
            auto nxt = copyEmo(clip, display);
            int nc = nxt.first, nd = nxt.second;
            if (nd <= 2000 && !visited[nd][nc]) {
                visited[nd][nc] = true;
                q.push({ nxt, cost + 1 });
            }
        }

        // 2. paste
        if (clip != 0) {
            auto nxt = pasteEmo(clip, display);
            int nc = nxt.first, nd = nxt.second;
            if (nd <= 2000 && !visited[nd][nc]) {
                visited[nd][nc] = true;
                q.push({ nxt, cost + 1 });
            }
        }

        // 3. delete
        if (display > 1) {
            auto nxt = deleteEmo(clip, display);
            int nc = nxt.first, nd = nxt.second;
            if (nd >= 0 && !visited[nd][nc]) {
                visited[nd][nc] = true;
                q.push({ nxt, cost + 1 });
            }
        }
    }

    cout << result << '\n';
    return 0;
}
