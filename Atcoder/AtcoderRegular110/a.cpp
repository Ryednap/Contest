#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

bool isPrime(int x){
	for(int i = 2; i <= sqrt(x); ++i) if(x %i == 0) return false;
	return true;
}

auto factorize(int x){
	map<int,int> m;
	for(int i = 2; i <= 30; ++i){
		if(isPrime(i)){
			while( x % i == 0){
				m[i]++;
				x /= i;
			}
		}
	} 
	return m;
}	

void solve(){
	int n;
	scanf("%d",&n);
	
	map<int,int> m;
	for(int i = 2; i <= n; ++i){
		map<int,int> v = factorize(i);
		for(pair<int,int> el : v){
			auto [a, cnt] = el;
			if(m[a] < cnt) m[a] = cnt;
		}
	}
	
	long long ans = 1;
	for(pair<int,int> x : m) ans *= pow( (ll) x.first, x.second);
	for(int i = 2; i <= n; ++i) assert( (ans + 1)%i ==1);
	printf("%llu",ans + 1);
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



