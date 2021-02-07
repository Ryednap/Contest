#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Another smart implementation of the problem

int main() {
	int p, g;
	scanf("%d %d", &p, &g);
	map<string, int> vote;
	for (int i = 0; i < p; ++i) {
		string s;
		double x;
		cin >> s >> x;
		vote[s] = x * 10;
	}
	
	cin >> ws;
	for(int i = 0; i < g; ++i) {
		string str; 
		getline(cin, str);	
		stringstream ss(str);
		int total = 0;
		string a, b;
		while( true ) {
		
			ss >> a >> b;
			if( b != "+") break;
			else total += vote[a];
		}
		int n;
		ss >> n;
		n *= 10;
		bool ok = false;
		if(b == "<" && total < n) ok = true;
		else if(b == "<=" && total <= n) ok = true;
		else if(b == ">" && total > n) ok = true;
		else if(b == ">=" && total >= n) ok = true;
		else if(total == n) ok = true;
		
		printf("Guess #%d is %s.\n", i + 1, ok ? "correct" : "incorrect");
	}
	return 0;
}


