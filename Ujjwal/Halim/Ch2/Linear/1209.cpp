#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int OO = (int)1e6;
// O(|s| * n * 21) complexity. |s| = length of each string, n = total number of strings.

int main( ) {
	string str;
	while( getline(cin, str) ) {
		array<string, 21> ar;
		ar[10] = str;
		
		string s = str;
		for(int i = 9; i >= 0; --i) {
			prev_permutation(s.begin(), s.end());
			ar[i] = s;
		}
		
		s = str;
		for(int i = 11; i < 21; ++i) {
			next_permutation(s.begin(), s.end());
			ar[i] = s;
		}
		
		
		int dist = 0;
		string ans = "";
		for(int i = 0; i < 21; ++i ) {
			const int n = (int)ar[i].length();
			int here = OO;
			for(int j = 1; j < n; ++j) {
				here = min(here, (int)abs(ar[i][j] - ar[i][j - 1])); 
			}
			if(here > dist) {
				ans = ar[i];
				dist = here;
			}
		}
		
		printf("%s%d\n", ans.c_str(), dist);
	}
		
	return 0;	
}
