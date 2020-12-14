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
 Beginner's level Greedy problem . for each segment of opposite sign just pick the maximum one. because each number from that segment contribute to one length. 
  
 */

void solve(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}
	
	long long sum = 0;
	for(int i = 0; i < n ;){
		
		int res = arr[i];
		int j = i + 1;
		for(; j < n && (long long)arr[i] * arr[j] > 0; ++j) res = max(res, arr[j]);

		sum += res;
		i = j;
	}
	
	printf("%lld\n", sum);
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



