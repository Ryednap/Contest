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
 Medium Level Construtive Range based problem. Infact the understanding the question itself as range based makes it's a bit hard and awesome. So if we did'nt had that 
 constraint that Ai = [1, k] then this was an easy greedy problem . But here the range of each pair matters by range i mean that -> Suppose we have a pair a, b such that
 a <= b . Now for x = [0, a] we have to change both numbers . From [a + 1, a + b - 1] we have 1 and from [a + b + 1, b + k] we have again 1 and from [b + k + 1, 2 * k]
  we have two change both the numbers. Now this becomes range query for each pair do this and then use the technique of array range- sum.  And then pick the minimum
  from the range [0, 2 * k ].
   */

const int OO = (int)1e9;



void solve(){
	int n, k;
	scanf("%d%d",&n,&k);
	
	int arr[n];
	
	vector<int> pref(2*k + 4);
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);	
	}
	
	
	auto Set = [&](const int & L, const int & R, const int & val){
		
		pref[L] += val;
		pref[R + 1] -= val;
	};
	
	for(int i = 0; i < n/2; ++i){
		int a = arr[i];
		int b = arr[n - i - 1];
		
		if(a > b) swap(a,b);
		
		Set(0, a, 2);
		Set(a + 1, a + b - 1, 1);
		Set(a + b + 1, b + k, 1);
		Set(b + k + 1, 2 * k, 2);
	}
	
	for(int i = 1; i < 2* k + 3; ++i){
		pref[i] += pref[i - 1];
	}
	
	int answer = OO;
	for(int i = 2; i < 2 * k + 1; ++i){
		answer = min(answer, pref[i]);
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



