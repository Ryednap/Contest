#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Medium Problem.
// I had got the idea just after reading it withing 8 min. But shitty implementation killed my chance to be in top 1k.
// The idea is that. if we try brute force then it's not gonna work. As we have option of removing edges what we can do always is to make tree
// once we have the tree it's always possible to satisfy the condition. How ? make the root node any number . Now every node from nowonwards will be numbered the
// previous edge in the tree. 

// There is a corner case when for a node upper and lower edge are same numbered . In that case we have to igonore the numbering of child's node . That's all.


const int NAX = 1e6;

vector<vector<pair<int,int > > > adj(NAX);
vector<vector<pair<int,int > > > when(NAX);
vector<bool> done(NAX,false);
int n , m; 
int ans[NAX];

void dfs1(int node){ // for making tree
	done[node] = true;
	for(pair<int,int> el : when[node]){
		if(!done[el.first]){
			adj[node].push_back(el);
			adj[el.first].push_back(make_pair(node, el.second));
			dfs1(el.first);
		}
	}
}

void dfs2(int node, int prev_col, int par_col, int par){
	if(prev_col == par_col){ // corner case
		vector<bool> used(n + 1, false);
		for(auto el : adj[node]) used[el.second] = true;
		for(int i = 1; i <= n ; ++i)  if(used[i] == false){
			ans[node] = i;
			break;
		}
		
	} else { // else normal
		ans[node] = prev_col;
	}
	
	assert(ans[node] != -1);
	for(auto el : adj[node]){ // pass the state.
		auto [a,b] = el;
		if(a != par) dfs2(a, b,ans[node], node);
	}
}
	


void solve(){

	scanf("%d %d",&n,&m);
	memset(ans,-1,sizeof(ans));

	for(int i =0 ; i < m ;++i){
		int a, b, c;
		scanf("%d %d %d",&a, &b, &c);
		--a,--b;
		when[a].push_back(make_pair(b,c));
		when[b].push_back(make_pair(a,c));
	}
	dfs1(0);
	vector<bool> used(n+1,false);
	for(pair<int,int> el : adj[0]){
		auto [a, b] = el;
		used[b] = true;
		dfs2(a, b, -1, 0);
	}
	for(int i = 1; i <= n; ++i) if(!used[i]){
		ans[0] = i;
		break;
	}
		
	
	for(int i = 0; i < n; ++i) assert(ans[i] != -1), printf("%d\n",ans[i]);
}


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



