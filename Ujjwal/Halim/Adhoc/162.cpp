#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)x.size())
#ifdef LOCAL
#include "uj.h"
#endif
     
int Val(char ch ) {
	if(isdigit(ch)) return 0;
	else if(ch == 'J') return 1;
	else if(ch == 'Q') return 2;
	else if(ch == 'K') return 3;
	else return 4;
}	

int main() {
	while(1) {
		string str;
		int turn = 1;
		vector<int> a, b;
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 13; ++j) {
				cin >> str;
				if(str == "#"  ) return 0;
				int val = Val(str[1]);
				if(turn) b.push_back(val);
				else a.push_back(val);
				turn ^= 1;
			}

		}

		vector<int> pile;
		int howMany = 0;
		turn = 1;
		auto Do = [&](auto &x) {
			int curr = x.back();
			x.pop_back();
			howMany = curr;
			pile.push_back(curr);

		};

		auto Special = [&](auto &x) {
			for(int i = 0; i < howMany; ++i) {
				int curr = x.back();
				x.pop_back();
				pile.push_back(curr);
				if(!curr) continue;
				howMany = curr;
				break;
			}
			std :: copy (x.begin(), x.end(), back_inserter(pile));
			x = pile;
			pile = vector<int>();
		};
			
		int cnt = 0;
		while(sz(a) && sz(b)) {
			debug() << owo(a) owo(b) owo(pile);
			if(howMany == 0) {
				if(turn) Do(b);
				else Do(a);
			} else {
				if(turn) Special(b);
				else Special(a);
			}
			//if(cnt == 5) break;
			++cnt;
			turn ^= 1;
		}

		if(sz(a)) printf("%d %d\n", 1, sz(a));
		else printf("%d %d\n", 2, sz(b));

	}
	return 0;
}	


			
