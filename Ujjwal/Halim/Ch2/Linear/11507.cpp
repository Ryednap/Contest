#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int Add(int a, int b) {
	return (( a + b) % 4 + 4)%4;
}

int Sub(int a, int b) {
	return ( ( a - b) % 4 + 4)%4;
}

bool Onx(int a) {
	if(a == 0 || a == 2) return true;
	else return false;
}

int main( ) {
	int n;
	while(scanf("%d", &n) && n) {
		
		int z = 0, y = 0;
		for(int i = 0; i < n - 1; ++i) {
			string s; cin >> s;
	
			if(s == "No") continue;
			
			if(s[1] == 'z' && Onx(y)) {
				if(y == 2) z = 2;
				y = 0;
				if(s[0] == '-') z = Sub(z, 1);
				else z = Add(z, 1);	
				
			} else if(s[1] == 'y' && Onx(z)) {
				if(z == 2) y = 2;
				z = 0;
				if(s[0] == '-') y = Sub(y, 1);
				else y = Add(y , 1);
			}	
		}

		if(z == 0 && y == 0) {
			puts("+x");
		} else if(y == 2 || z == 2) {
			puts("-x");
			
		} else if(y == 1) {
			puts("+y");
		} else if(y == 3) {
			puts("-y");
		} else if(z == 1) {
			puts("+z");
		} else puts("-z");
	}
	return 0;		
}
