#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif
const int OO = (int)1e7;

int main() {
	int qq,tt =0;
	scanf("%d", &qq);
	while( qq-- ) {
		int n;
		scanf("%d",&n);
		map<string, int> mapper;
		for(int i = 0; i < n; ++i) {
			string s; int d;
			cin >> s >> d;
			mapper[s] = d;
		}
		
		int D ; scanf("%d", &D);
		printf("Case %d: ", ++tt);
		string s; cin >> s;
		if(mapper.find(s) != mapper.end()) {
			int x = mapper[s];
			if(x <= D) puts("Yesss");
			else if(x <= D + 5) puts("Late");
			else puts("Do your own homework!");
		} else {
			puts("Do your own homework!");
		}
	}
	return 0;
}


