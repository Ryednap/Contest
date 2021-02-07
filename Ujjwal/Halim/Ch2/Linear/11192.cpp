#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O( |s| * n) direct adhoc

int main( ) {
	int g;
	while( scanf("%d", &g) ) {
		if(g == 0) break;
		string str;
		cin >> str;
		const int n = (int)str.length();
		assert(n % g == 0);
		int x = n / g;
		string ans = "", part = "";
		for(char ch : str) {
			part += ch;
			if((int)part.length() == x) {
				reverse(part.begin(), part.end());
				ans += part;
				part = "";
			}
		}
		puts(ans.c_str());
	}
	
	return 0;	
}
