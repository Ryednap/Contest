#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int a, b, c;
		bool gameEnd = false;
		scanf("%d %d %d", &a, &b, &c);
		int players[a] = {0};
		map<int, int> snakes, ladder;
		while(b--){
			int start, end;
			scanf("%d %d", &start, &end);
			if(start > end){
				snakes[start-1] = end-1;
			}else{
				ladder[start-1] = end-1;
			}
		}
		int cnt = 0;
		while(c--){
			int temp;
			scanf("%d", &temp);
			if(!(gameEnd)){
				players[cnt] += temp;
			}
			if(snakes.find(players[cnt]) != snakes.end() && !(gameEnd)){
				players[cnt] = snakes[players[cnt]];
			}else if(ladder.find(players[cnt]) != ladder.end() && !(gameEnd)){
				players[cnt] = ladder[players[cnt]];
			}
			if(players[cnt] >= 99){
				gameEnd = true;
				players[cnt] = 99;
				continue;
			}
			cnt = (cnt+1)%a;
			
		}
		for(int i=0; i<a; i++){
			printf("Position of player %d is %d.\n", i+1, players[i] + 1);
		}
	}
			
	return 0;
}
