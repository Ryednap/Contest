#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Altough the value of each word is real number and also no info on decimal precision we can assume that it's integers.

// Easy level 1 
// Reading and Understanding 3 min 36 sec
// No time on thinking as the problem straightforward
// 5 min and 4 sec on coding
// 2 min 29 sec on debugging and verification

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	map<string, int> mapper;
	for(int i = 0 ; i < m; ++i) {
		string s; int cost;
		cin >> s >> cost;
		mapper[s] = cost;
	}

	cin >> ws;
	for(int i = 0; i < n; ++i) {
		string str; 
		int cost = 0;
		while (getline(cin, str) && str != ".") {
		
			stringstream ss(str);
			string inp ; 
			while ( ss >> inp ) {
				cost += mapper[inp];
			}
		}
		printf("%d\n", cost);
	}
			
	return 0;
}


