#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Note the priority :

// 4 WA because of trying to remove all the piles at once
// It said if possible move the left one possible
// Then i - 3 or i - 1.

using vs = vector<string>;

int main( ) {
	while(true) {
		vector<vs> cards;
		for(int _ = 0; _ < 2; ++_) {
			for(int i = 0; i < 26; ++i) {
				string s; cin >> s;
				if(s == "#") return 0;
				vs st; st.push_back(s);
				cards.push_back(st);
			}
		}
		
		auto Match = [&] (int a, int b) {
			string & s = cards[a].back();
			string & t = cards[b].back();
			return ( s[0] == t[0] ) || ( s[1] == t[1] );
		};
		
		bool ok = true;
		while( ok ) {
			ok = false;
			for(int i = 1; i < (int)cards.size(); ++i) {
				if(i - 3 >= 0 && Match(i , i - 3)) {
					cards[i - 3].push_back( cards[i].back() );  cards[i].pop_back();
					if(cards[i].empty()) cards.erase(cards.begin() + i);
					ok = true;
					break;	
					
				} else if(Match(i, i - 1)) {
					cards[i - 1].push_back( cards[i].back() );  cards[i].pop_back();
					if(cards[i].empty()) cards.erase(cards.begin() + i);
					ok = true;
					break;
					
				}
			}
		}
		
		const int n = (int)cards.size();
		if(n == 1) printf("%d pile remaining:", n);
		else printf("%d piles remaining:", n);
		
		for(auto s : cards) {
			printf(" %d", (int)s.size());
		}
		puts(""); 	
	}	
		
	return 0;	
}
