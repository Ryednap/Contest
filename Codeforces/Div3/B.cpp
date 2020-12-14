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
 Constructive (Easy). The question is based on the fact that whenever the difference b/w the sum of even and odd is even we have a solution . Why ? note that the even
 sum if always greater than odd sum. If the difference is even then we can replace the last odd number to ( number + even_diff). as odd + even is odd we have solution 
  but not vice-versa.
 */

void solve(){
	int n;
	
	scanf("%d",&n);
	n >>= 1;

	if( !(n & 1) ){
		puts("YES");
		for(int i = 1; i <= n; ++i){
			printf("%d ",2 * i);
		}
		
		for(int i = 1; i <= n - 1; ++i){
			printf("%d ",2 * i - 1);
		}
		
		printf("%d\n",2 * n - 1 + n);
	
	} else {
		puts("NO");
	}
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



