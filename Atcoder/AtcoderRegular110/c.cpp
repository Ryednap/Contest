#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

struct Node{
	int a, b ;
	Node() {}
	Node(int x, int y) : a(x), b(y) {}
	
	bool operator < (const Node & n) const{
		return ( abs ( a - b ) > abs( n.a - n.b));
	}
};

void solve(){
	int N;
	scanf("%d",&N);
	
	int arr[N];
	for(int i = 0; i < N: ++i) scanf("%d",&arr[i]);
	
	priority_queue<Node> q;
	
	for(int

int main(){
	int tt;
	//scanf("%d",&tt);
	tt = 1;
	for(int _ = 1;_ <=tt;++_ ){
		solve();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}



