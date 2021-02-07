#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A very traditional question for stack
// O(n^2) complexity but i feel that it can be done in O(n Logn) time some data-structres 

// The idea is that once we are at some number in th sequeunce then the next number or element can either be previous or the any after the current number
// in the original stack. eg .. a b  c d e f g.  If we are at d then next can be c or e or f or g anything other than is invalid as stack always preserve
// order .

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
