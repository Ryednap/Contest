#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Level 1 problem 3 min coding.

int main() {
	int n; scanf("%d",&n);
	cin >> ws;
	map<string, string> mapper;
	for(int i = 0; i< n; ++i) {
		string a, b;
		getline(cin, a);
		getline(cin, b);
		mapper[a] = b;
	}
	int qq; scanf("%d",&qq);
	cin >> ws;
	while( qq-- ) {
		string s;
		getline(cin, s);
		assert(mapper.find(s) != mapper.end());
		puts(mapper[s].c_str());
	}
	
	return 0;
}


