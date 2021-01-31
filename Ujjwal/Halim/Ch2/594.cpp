#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int n;
	while( scanf("%d", &n) != EOF ) {
		long long answer = 0, copy = n;
		bitset<32> bs;
		bs[24] = 1;
		cout << bs.to_ulong() << endl;
	} 
	
	return 0;	
}
