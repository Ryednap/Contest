#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
#define f first
#define s second
#define pb(x) push_back(x)

inline static void ltrim(std :: string & s) {
	s.erase(s.begin(), std :: find_if(s.begin(), s.end(), [] (unsigned char ch ) {
		return !std :: isspace(ch);
	}));
}
inline static void rtrim(std :: string & s) {
	s.erase(std :: find_if(s.rbegin(), s.rend(), [] (unsigned char ch) { 
		return !std :: isspace(ch);
	}).base(), s.end());
}

inline static void trim(std :: string & s) {
	ltrim(s); rtrim(s);
}

// damn 6 WA fucking what's wrong. I need to break my own code now whenever i have got much time.

int main() {
	int n;
	scanf("%d", &n);
	vector<vi> block(n);
	for(int i = 0; i < n; ++i) {
		block[i].pb(i);
	}
	auto Find = [&](int a) {
		for(int i = 0; i < n; ++i) {
			for(const int & x : block[i]) {
				if(x == a) {
					return i;
				}
			}
		}
		//debug() << owo(block);
		assert(false);
		return -1;
	};
	
	auto Clear = [&] (int a) {
		int j = Find(a);
		vi & v = block[j];
		while(v.back() != a) {
			int x = v.back();
			v.pop_back();
			assert((int)block[x].size() == 0);
			block[x].pb(x);
		}
	};
	
	auto Move = [&] (int a, int b) {
		int p = Find(a);
		int q = Find(b);
		vi & v = block[p], & u = block[q];
		
		// move v to u
		vector<int> temp;
		while((int)v.size()) {
			int x = v.back(); v.pop_back();
			temp.pb(x);
			if(x == a) break;
		}
		reverse(temp.begin(), temp.end());
		for(int & x : temp) {
			u.pb(x);
		}
	};
	
	string str;
	cin >> ws;
	while( getline(cin,str) ) {
		trim(str);
		if(str == "quit") break;
		stringstream ss(str);
		string p1, p2;
		int a, b;
		//debug() << owo(str);
		ss >> p1 >> a >> p2 >> b;
		trim(p1); trim(p2);
		if(p1 == "move") {
			Clear(a);
		}
		if(p2 == "onto") {
			Clear(b);
		}
		//debug() << owo(block);
		Move(a, b);
	}
	for(int i = 0; i < n; ++i) {
		printf("%d:", i);
		for(int & x : block[i]) {
			printf(" %d", x);
		}
		puts("");
	}
	return 0;
}
		
