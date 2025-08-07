#include <bits/stdc++.h>

int isPalindrome(const std::string& str, int left, int right, int depth) {
    if (depth == 2) return 2;  

    while (left < right) {
        if (str[left] == str[right]) {
            left++;
            right--;
        }
        else {
            if (depth == 1) return 2; 
            bool skipLeft = isPalindrome(str, left + 1, right, depth + 1) < 2;
            bool skipRight = isPalindrome(str, left, right - 1, depth + 1) < 2;
            return (skipLeft || skipRight) ? 1 : 2;
        }
    }

    return (depth == 0) ? 0 : 1; 
}

int main() {
    int N; std::cin >> N;

    while (N--) {
        std::string s; std::cin >> s;
        std::cout << isPalindrome(s, 0, s.size() - 1, 0) << '\n';
    }

    return 0;
}
