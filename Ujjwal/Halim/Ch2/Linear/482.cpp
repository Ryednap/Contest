#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n) just do what is asked.

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		cin >> ws;
		string str;
		getline(cin, str);
		stringstream ss(str);
		int x;
		vector<int> p;
		while( ss >> x ) {
			p.push_back(x);
		}
	
		const int n = (int)p.size();
		string arr[n + 1];
		for(int i = 0; i < n ; ++i) {
			cin >> arr[p[i]];
		}
		
		for(int i = 1; i <= n; ++i) {
			puts(arr[i].c_str());
		} 
		if(qq) puts("");
	}
			
	return 0;	
}
