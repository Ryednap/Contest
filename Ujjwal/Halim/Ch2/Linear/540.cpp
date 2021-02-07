#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(qq) where qq = number of commands
// Sample case from my side :- 

//3
//2 2 1
//1 3
//1 4
//ENQUEUE 2
//ENQUEUE 2
//ENQUEUE 3
//DEQUEUE
//ENQUEUE 4
//ENQUEUE 1
//DEQUEUE
//DEQUEUE
//STOP

const int nax = (int)1e6 + 10;
int main( ) {
	int t, tt = 0;
	while(scanf("%d", &t) && t) {
		array<int, nax> team;
		for(int i = 0; i < nax; ++i) {
			team[i] = -1;
		}
		
		for(int _ = 0 ; _ < t; ++_) {
			int n;  scanf("%d", &n);
			for(int i = 0; i < n; ++i) {
				int x ;
				scanf("%d", &x);		
				team[x] = _;
			}
		}
		

		string command;
		queue<int> q; // q contains team
		vector<queue<int >> vq (t + 1);
		
		printf("Scenario #%d\n", ++tt);
		while(cin >> command) {
			if(command == "STOP") break;
			else if(command == "ENQUEUE") {
				int x;  scanf("%d",&x);
				int y = team[x];
				if(vq[y].empty()) {
					q.push(y);
				}
				vq[y].push(x);
				
			} else {
				int y = q.front();
				int x = vq[y].front(); vq[y].pop();
				printf("%d\n", x);
				if(vq[y].empty()) q.pop();
			}
		}
		puts("");
	}
	
	return 0;	
}
