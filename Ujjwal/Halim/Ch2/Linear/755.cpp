#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*Adhoc no comment
 */

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n;
		scanf("%d", &n);
		map<char, char> mapper;
		char cnt = '1';
		string alpha = "ABCDEFGHIJKLMNOPRSTUVWXY";
		for(int i = 0; i < (int)alpha.size(); ++i) {
			char ch = alpha[i];
			if(i % 3 == 0) ++cnt;
			mapper[ch] = cnt;
		}
		
		map<string, int> lib;
		for(int i = 0; i < n; ++i) {
			string number, s = "";
			cin >> number;
			for(char ch : number) {
				if(ch == '-') continue;
				if(!isdigit(ch)) s += mapper[ch];
				else s += ch;
				if((int)s.length() == 3) s += '-';
			}

			lib [s] ++;
		}
		
		bool printed = false;
		for(auto p : lib) {
			if(p.second > 1) {
				printf("%s %d\n", p.first.c_str(), p.second);
				printed = true;
			}
		}
		
		if(!printed) puts("No duplicates.");
		if(qq) puts("");
	}
			
	return 0;	
}
