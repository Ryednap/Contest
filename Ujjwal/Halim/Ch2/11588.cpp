#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

// O(nlogn). sort the map by the value.

int main( ) {
	int qq, tt = 0;
	scanf("%d", &qq);
	while(qq--) {
		int n, m, a, b;
		scanf("%d %d %d %d", &n, &m, &a, &b);
		map<char, int> mapper;
		for(int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for(char & ch : s) {
				mapper[ch]++;
			}
		}
		vector<pair<char,int>> v (mapper.begin(), mapper.end());
		auto cmp = [] (const pair<char, int> & p1, const pair<char, int> & p2) {
			return p1.s > p2.s;
		};
		sort(v.begin(), v.end(), cmp);
		int maxi = v[0].s;
		int answer = 0;
		for(auto p : v) {
			if(p.s == maxi) answer += a * maxi;
			else answer += b * p.s;
		}
		printf("Case %d: %d\n", ++tt, answer);
	}
	
	return 0;	
}
