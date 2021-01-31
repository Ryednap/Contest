#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(!n) break;
		cin >> ws;
	
		while(true) {
			string str;
			getline(cin, str);
			stringstream ss(str);
			array<int, 1001> done = {false};
			int sig = -1, past = -1, x;
			if(str == "0") break;
			
			while(ss >> x) {
	
				if(past == -1) {
					past = x;
					done[x] = true;
					sig = 1;
					
				} else if(past < x) {
					done[x] = true;
					past = x;
					
				} else {
					int diff = 0;
					for(int i = past ; i >= x; --i) {
						if(!done[i]) ++diff;
					}
					done[x] = true;
					if(diff > 1) {
						sig = false;
						break;
					}
				}
			}
			if(sig == -1) break;
			puts(sig ? "Yes" : "No");
		}
		puts("");
	}
	
	return 0;	
}
