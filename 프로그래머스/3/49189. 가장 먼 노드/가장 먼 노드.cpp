#include <bits/stdc++.h>

std::vector<std::vector<int>> graph;
std::vector<int> visited;
std::vector<int> result(20001);

void BFS(int start){
    std::queue<std::pair<int, int>> q;
    q.push({start, 1});
    visited[start] = 1;
    
    while (!q.empty()){
        auto current = q.front();
        q.pop();
        result[current.second]++;
        for (auto next: graph[current.first]){
            if (visited[next] == 0){
                visited[next] = 1;
                q.push({next, current.second + 1});
            }
        }
    }
}

int solution(int n, std::vector<std::vector<int>> edge) {
    graph.resize(n + 1);
    visited.resize(n + 1, 0);
    for (int i = 0 ; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    BFS(1);
    for (int i = 1; i < result.size(); i++){
        if (result[i] == 0){
            return result[i - 1];
        }
    }
}