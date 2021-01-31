#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif
// A bit mathematical
/**
 * Consider a downward triangle in the problem image on the top now assume a b c as their value, then ATQ :- 	a + b = 255, 54 + c = a , 67 + c = b
 * solving these 3 we get 54 + c + 67 + c = 255. So get the value of c and then a and b and also note that this pattern can be seen in the whole 
 * configuration. so we just need to solve for it.
 * 
 */

using vi = vector<int>;

int main( ) {
	int qq;
	scanf("%d" ,&qq);
	while( qq-- ) {
		vector<vi> v(10);
		for(int i = 1; i < 10; ++i) {
			v[i].resize(i + 1);
			if(i & 1) {
				for(int j = 1; j <= i; j += 2) {
					 scanf("%d", &v[i][j]);
				}
			}
		}
		
		for(int i = 2; i < 10; i += 2) {
			for(int j = 1; j <= i; j += 2) {
				int c = -v[i + 1][j] - v[i + 1][j + 2] + v[i - 1][j];
				assert(c % 2 == 0);
				c /= 2;
				v[i + 1][j + 1] = c;
				v[i][j] = v[i + 1][j] + v[i + 1][j + 1];
				v[i][j + 1] = v[i + 1][j + 1] + v[i + 1][j + 2];
			}
		}
		
		for(int i = 1; i < 10; ++i) {
			printf("%d", v[i][1]);
			for(int  j = 2; j <= i; ++j) {
				printf(" %d", v[i][j]);
			}
			puts("");
		}
	}
	return 0;	
}
