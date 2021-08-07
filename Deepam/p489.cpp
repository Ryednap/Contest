#include <bits/stdc++.h>
using namespace std;
int main(){
	int R = 0;
	char c;
	while(true){
		cin >> R;
		if(R == -1){
			break;
		}
		cin.ignore();
		vector<char> solution, guess;
		int strokeCount = 0, matchCount = 0;
		while(true){
			c = getchar();
			if(c == '\n'){
				break;
			}
			if(find(solution.begin(), solution.end(), c) == solution.end()){
				solution.push_back(c);
			}
		}
		c = '1';
		while(true){
			c = getchar();
			if(c == '\n'){
				break;
			}
			if(matchCount == (int)solution.size() || strokeCount == 7){
				continue;
			}
			if(find(solution.begin(), solution.end(), c) != solution.end() && find(guess.begin(), guess.end(), c) == guess.end()){
				matchCount++;
				guess.push_back(c);
			}else if(find(guess.begin(), guess.end(), c) == guess.end()){
				strokeCount++;
				guess.push_back(c);
			}
			
			
		}
		if(matchCount == (int)solution.size()){
			printf("Round %d\nYou win.\n", R);
		}else if(strokeCount == 7){
			printf("Round %d\nYou lose.\n", R);
		}else{
			printf("Round %d\nYou chickened out.\n", R);
		}
	}
	return 0;
}
	
