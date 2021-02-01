#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main( ) {
	int tt = 0;
	string  str;
	while( cin >> str && str != "end") {
		int answer = 0;
		const int n = (int)str.length();
		reverse(str.begin(), str.end());
		vector<int> done(n, false);
		
		
		for(int i = 0; i < n; ++i) {
			if(done[i]) continue;
			map<char, int> invalid;
			
			function < void(int) > Set = [&] (int idx) {
				int last = idx;
				for(int j = idx; j < n; ++j) {
						if(str[idx] == str[j]) {
							done[j] = true;
							last = j;
						};
				}
				
				for(int j = idx; j < last; ++j) {
					if(str[j] != str[last]) invalid[str[j]] = true;
				}
				
				for(int j = last + 1; j < n; ++j) {
					if(!invalid[j] && !done[j] && str[j] > str[last]) {
						Set(j);
						return;
					}
				}
			};
			
			Set(i);
			++answer;
		}
					
		printf("Case %d: %d\n", ++tt, answer);
	}
	
	return 0;	
}
