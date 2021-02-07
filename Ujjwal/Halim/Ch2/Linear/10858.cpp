#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Analyze the complexity.

static inline bool isPrime(const int & x ) {
	if(x == 2 || x == 3) return true;
	if(x % 2 == 0 || x % 3 == 0) return false;
	
	for(int i = 5; i <= sqrt(x); i += 2) {
		if( x % i == 0) return false;
	}
	return true;
}

using vi = vector<int>;

static inline vi Add(const vector<int> & a, const vector<int> & b) {
	vi v;
	for(auto & x : a) v.push_back(x);
	for(auto & x : b) v.push_back(x);
	sort(v.begin(), v.end());
	return v;
}

int main( ) {
	int n;
	while(scanf("%d", &n) and n != 0) {
		
		if(isPrime(n)) {
			puts("0");
			continue;
		}

		function < set<vi> (int) > Factor = [&](int x) {
			if(isPrime(x)) {
				set<vi> s;
				s.insert(vi(1,x));
				return s;
			} 
			
			set<vi> v;
			for(int i = 2; i <= sqrt(x); ++i) {
				if(x % i == 0) {
					set<vi> a = Factor(i);
					set<vi> b = Factor(x / i);		
					a.insert(vi(1,i));
					b.insert(vi(1,x/i));
					for(auto l : a) {
						for(auto m : b) {
							v.insert(Add(l, m));
						}
					}
				}
			}
			return v;
		};
		
		
		auto ans = Factor(n);
		printf("%d\n", (int)ans.size());
		for(auto v : ans) {
			printf("%d", v[0]);
			for(int i = 1; i < (int)v.size(); ++i) {
				printf(" %d", v[i]);
			}
			puts("");
		}		
	}
	
	return 0;	
}
