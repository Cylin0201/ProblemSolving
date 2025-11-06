#include <bits/stdc++.h>

bool isOk(int n, const std::vector<int>& times, long long mid){
    long long res = 0;
    for (const auto& t: times){
        res += mid / t;
        
        if (res >= n) return true;
    }
    return res >= n;
}

long long solution(int n, std::vector<int> times) {
    long long low = 1, high = (long long) *std::max_element(times.begin(), times.end()) * n;
    long long answer = high;
    
    while (low <= high){
        long long mid = (low + high) / 2;
        
        if (isOk(n, times, mid)){
            answer = mid;
            high = mid - 1;
        }
        else low = mid + 1; 
    }
    return answer;
}