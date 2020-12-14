#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 Fairly beginners . O(Log N).  
 Infact the maximum loop run time will never excced 32.
 */

void solve(){
	int n;
	scanf("%d",&n);
	
	int answer = -1;
	for(int curr = 2; ; ++curr){
		
		long long x = ( 1LL << curr) - 1;
		if(n % x == 0){
			answer = n/x;
			break;
		}
	}
	
	printf("%d\n",answer);
}


int main(){
	int tt;
	
	scanf("%d",&tt);
	for(int _ = 1;_ <=tt;++_ ){
		solve();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}



