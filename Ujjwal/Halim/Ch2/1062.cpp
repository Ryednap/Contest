#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main( ) {
	int tt = 0;
	string str;
	while( cin >> str && str != "end") {
		const int n = (int)str.length();
		vector<int> done(n, false);
		reverse(str.begin(), str.end());
		map<char, int> last;
		
		for(int i = 0; i < n; ++i) {
			last[str[i]] = i;
		}
		
		auto Set = [&](const int &x) {
			for(int i = 0; i < n; ++i) {
				if(str[i] == str[x]) done[i] = true;
			}
		};
		
		int answer = 1;
		pair<char, int> prev = {str[0], 0};
		
		for(int i = 1; i < n; ++i) {
			if(done[i]) continue;
			if(str[i] < prev.f) {
				
				vector<bool> together(n, false);
				for(int j = prev.s; j <= last[prev.f]; ++j) {
					together[j] = false;
				}
				
				char c = prev.f;
				for(int j = last[prev.f] + 1; j < n; ++j) {
					if(!done[j] && str[j] >= c) {
						c = str[j];
						Set(j);
					}
				}
				
				Set(prev.s);
				++answer;
				prev = {str[i], i};
			} else prev = {str[i], i};
		}
		printf("Case %d: %d\n", ++tt, answer);
	}
	
	return 0;	
}
