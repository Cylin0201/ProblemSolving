#include <bits/stdc++.h>

bool is_adjacent(const std::string& a, const std::string& b) {
    int diff = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int solution(std::string begin, std::string target, std::vector<std::string> words) {
    std::queue<std::pair<std::string, int>> q;
    std::vector<bool> visited(words.size(), false);
    
    q.push({begin, 0});
    
    while (!q.empty()) {
        auto [current, depth] = q.front(); q.pop();
        
        if (current == target) return depth;
        
        for (int i = 0; i < words.size(); ++i) {
            if (!visited[i] && is_adjacent(current, words[i])) {
                visited[i] = true;
                q.push({words[i], depth + 1});
            }
        }
    }
    
    return 0;
}
