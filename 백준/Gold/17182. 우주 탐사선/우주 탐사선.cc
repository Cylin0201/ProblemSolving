#include <bits/stdc++.h>

using namespace std;

int N, K, result = 1e9;
vector<vector<int>> arr;
vector<bool> visited;

//idx = 현재 행성
//dist = 현재 행성까지 거리
//planet = 방문한 행성 수
void dfs(int idx, int dist, int planet) {
    if (result < dist) return; //최솟값이 아니라면 무시
    
    if (planet == N) { //모든 행성 방문완료 시
        result = min(result, dist); //최솟값 갱신
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue; //방문 행성 무시
        visited[i] = true; //방문 표시
        dfs(i, dist + arr[idx][i], planet + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> K;
    arr.assign(N, vector<int>(N));
    visited.assign(N, false);

    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> arr[i][j];

    visited[K] = true; //시작점 방문 체크

    for (int k = 0;k < N;k++)
        for (int i = 0;i < N;i++)
            for (int j = 0; j < N;j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    dfs(K, 0, 1);

    cout << result;
}
