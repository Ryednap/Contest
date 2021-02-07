#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// optimizations;

int main( ) {
	string a, b;
	while( cin >> a >> b ) {
		const int n = (int)a.size() * 2;
		const int m = (int)b.size() * 2;
		
		auto Valid = [&] (vector<int> op) {
			if(n != m) return false;
			stack<char> s;
			int curr = 0, idx = 0;
			for(int i = 0; i < n; ++i) {
				if(op[i]) {
					if(s.empty()) return false;
					if(s.top() != b[idx++]) return false;
					s.pop();
					
				} else {
					s.push(a[curr++]);
				}
			}
			return true;
		};
			
		vector<vector<int>> ans;
		for(int i = 0; i < (1 << n); ++i) {
			vector<int> v;
			int z = 0, o = 0;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) v.push_back(1), ++o;
				else v.push_back(0), ++z;
			}
			if(z != o) continue;

			if(Valid(v)) ans.push_back(v);
		}
		sort(ans.begin(),ans.end());
		puts("[");
		for(auto v : ans) {
			printf("%c", v[0] ? 'o' : 'i');
			for(int i = 1; i < (int)v.size(); ++i) {
				printf(" %c", v[i] ? 'o' : 'i');
			}
			puts("");
		}
		puts("]");
			
	}
	return 0;	
}
