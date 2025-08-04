#include <bits/stdc++.h>
bool visited[26];

int main() {
    int N; std::cin >> N;
    int cnt = N;
    for (int i = 0; i < N; i++) {
        std::fill(visited, visited + 26, false);
        std::string input; std::cin >> input;
        for (int j = 0; j < input.size(); j++) {
            if (!visited[input[j] -'a']) {
                visited[input[j] -'a'] = true;
                while (j + 1 < input.size() && input[j + 1] == input[j])
                    j++;
            }
            else {
                cnt--;
                break;
            }
        }
    }
    std::cout << cnt << '\n';

    return 0;
}