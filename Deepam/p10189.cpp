#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	int cnt = 1;
	cin >> n >> m;
	while(true){
		
		cin.ignore();
		int mines[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				mines[i][j] = 0;
			}
		}
		for(int i=0; i<n; i++){			
			for(int j=0; j<m; j++){
				char temp;
				cin >> temp;
				if(temp == '*'){
					for(int r = (i-1); r < (i+2); r++){
						for(int s = (j-1); s < (j+2); s++){
							if(r > (n-1) || r < 0 || s > (m-1) || s < 0 || (s == j && r == i)){
								continue;
							}
							if(mines[r][s] == -1){
								continue;
							}
							mines[r][s] += 1;
						}
					}
					mines[i][j] = -1;
				}else if(temp == '.'){
					continue;
				}
			}
		}
		printf("Field #%d:\n", cnt);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(mines[i][j] == -1){
					cout << "*";
					continue;
				}
				cout << mines[i][j];
			}
			cout << endl;
		}
		cin >> n >> m;
		if(n == 0 || m ==0 ){
			break;
		}else{
			cout << endl;
		}
		cnt++;
	}
	return 0;
}
