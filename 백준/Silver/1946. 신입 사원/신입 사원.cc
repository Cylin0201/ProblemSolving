#include <bits/stdc++.h>

int main(){
	int T;
	int result;
	std::cin >> T;
	while(T > 0){
		int N; std::cin >> N;
		std::vector<std::pair<int, int>> v;
		
		for(int i=0; i < N; i++){
			int a, b;
			std::cin >> a >> b;
			v.push_back({a,b});
		}
		std::sort(v.begin(), v.end());
		
		int tmp = 0;
		result = 1;
		for(int i = 1; i < N; i++){
			if(v[tmp].second > v[i].second){
				result++;
				tmp = i;
			}
		}
		std::cout << result << '\n';
		T--;
	}
}