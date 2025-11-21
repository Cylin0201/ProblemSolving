#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  cin >> N;
    int ans = 0;
    std::string input; cin >> input;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
            ans++;
    }

    cout << ans << '\n';

    return 0;
}