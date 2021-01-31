#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	string str, inp;
	while( getline(cin, str) ) {
		if(str == "#") break;
		vector<vector<string >> cards(52);
		
		int idx = 0;
		for(int _ = 0; _ < 2; ++_) {
			stringstream ss(str);
			while(ss >> inp) {
				cards[idx++].push_back(inp);
			}
			getline(cin, str);
		}
	
	
		auto Valid = [] (string & a, string & b) {
			return (a[0] == b[0] || a[1] == b[1]);
		};
		

		
		bool ok = true;
		
		do {
			
			ok = false;
			int n = (int)cards.size();
			for(int i = 1; i < n; ++i) {
				n = (int)cards.size();
				
				auto Move = [&](int x, int y) {
					while((int)cards[y].size() > 0 && Valid(cards[x].back(), cards[y].back())) {
						ok = true;
						cards[x].push_back(cards[y].back());
						cards[y].pop_back();
					}
				};
				
				if(i >= 3 && Valid(cards[i].back(), cards[i -1].back())) {
					Move(i - 3, i);
				} else {
					Move(i - 1, i);
				} 
				
				if((int)cards[i].size() == 0) cards.erase(cards.begin() + i);
			}
			
			
		} while(ok) ;
		

		const int n = (int)cards.size();
		printf("%d piles remaining:", n);
		for(int i = 0; i < n; ++i) {
			printf(" %d", (int)cards[i].size());
		}
		puts("");
			
	}
	
	return 0;	
}
