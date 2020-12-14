#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/* Hard Graph - Shortest Path Problem
 * 
 */

void solve(){
	int n, m;
	scanf("%d%d",&n,&m);
	
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	
	int prices[m];
	for(int i = 0; i < m; ++i){
		scanf("%d",&prices[i]);
	}
	
	vector<int> adj[n + 1];
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	sort(prices, prices + m);
	
	
	


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



