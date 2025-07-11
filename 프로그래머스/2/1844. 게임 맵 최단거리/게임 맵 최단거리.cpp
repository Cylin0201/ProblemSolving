#include <bits/stdc++.h>
//0은 벽, 1은 벽이 없는 자리
// 최종은 n,m

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int BFS(std::vector<std::vector<int>>& maps, int n, int m){
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    maps[0][0] = 1; 
    
    while (!q.empty()){
        auto current = q.front();
        q.pop();
        
        for (int i = 0 ; i < 4; i++){
            int nx = dx[i] + current.first, ny = dy[i] + current.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1){
                q.push({nx, ny});
                maps[nx][ny] = maps[current.first][current.second] + 1;
            }
        }
    }
    return (maps[n-1][m-1] == 1) ? -1 : maps[n-1][m-1];
}

int solution(std::vector<std::vector<int>> maps){
    int n = maps.size(), m = maps[0].size();
    
    return BFS(maps, n, m);
}