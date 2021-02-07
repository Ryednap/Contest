#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Just a trivial problem just take care of order .

int main() {
	string str;
	// I don't know why but do you guys think problem should hide the input format to make it hard ?
	// I had guessed that maybe they have multiple cases but never thought those are to be compiled into one cases
	map<int, int> mapper;
	map<int, int> done;
	vector<int> v;
	while( getline(cin, str) ){
		int x;
		stringstream ss(str);
		
		while( ss >> x ) {
			mapper[x]++;
			if (!done[x]) {
				v.push_back(x);
				done[x] = true;
			}
		}
		
		
	}
	for (auto n : v) {
			printf("%d %d\n", n, mapper[n]);
		}
	return 0;
}


