#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


// question should have been more clear about the order meaning , if left, right, left occurs and we can both the left should i take or break;

int main( ) {
	int qq;
	scanf("%d", &qq);
	while(qq--) {
		int l, m;
		scanf("%d%d", &l, &m);
		array<queue<int>, 2> bank;
		l *= 100;
		for(int i = 0 ;i < m; ++i) {
			int x; string s;
			cin >> x >> s;
			if(s == "left") {
				bank[0].push(x);
			} else bank[1].push(x);
		}
		
		auto Valid = [&] () {
			if(!bank[0].empty()) return true;
			if(!bank[1].empty()) return true;
			return false;
		};
		
		int c = 0, answer = 0;
		while(Valid()) {
			int total = 0;
			queue<int> &q = bank[c];
			while(!q.empty()) {
				int x = q.front();
				if(total + x > l) break;
				total += x;
				q.pop();
			}
			++answer;
			c ^= 1;
		}
		
		printf("%d\n", answer);
	}
			
	return 0;	
}
