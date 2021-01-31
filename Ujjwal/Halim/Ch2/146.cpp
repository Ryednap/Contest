#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	string str;
	while( getline(cin, str) ) {
		if(str == "#") break;
		if(next_permutation(str.begin(), str.end())) {
			puts(str.c_str());
		
		} else puts( "No Successor");
	}

	return 0;	
}
