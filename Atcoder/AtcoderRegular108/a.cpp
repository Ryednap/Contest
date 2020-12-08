#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// I made a dumb mistake here i forgot to put double at the line 19 really bad. Make note of that . 
// There is another way also we can do brute force in O(sqrt(n)) as it's like factorizing m to x * y;
const double EPS = 1e-6;

inline void solve(){
	long long n , m;
	scanf("%llu %llu",&n,&m);
	bool ok = false;
	double d = ( (double)n * n - 4 * m); 
	if(d >= 0){
		long long a = (n + sqrt(d))/2;
		long long b = (n - sqrt(d))/2;
		if(a > 0 && b > 0){
			if(a + b == n && a * b == m) ok = true;
			else ok = false;
		}
	} else ok = false;
	
	printf("%s",(ok ? "Yes" : "No"));
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



