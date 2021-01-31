#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<long long>;

int main( ) {
	int qq, tt = 0;
	scanf("%d", &qq);
	while( qq-- ) {
		char buff [10];
		int n;
		scanf("%s %s %d", buff, buff, &n);
		printf("Test #%d: ", ++tt);	
		
		vector<vi> mat(n, vi(n));
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%lld", &mat[i][j]);
				ok &= mat[i][j] >= 0;
			}
		}
		

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) {
					ok &= mat[i][j] == mat[n - i - 1][n - j - 1];
					
				} else if(i + j == n - 1) {
					ok &= mat[i][j] == mat[j][i];
				} else {
					ok &= mat[i][j] == mat[i][n - j - 1];
					ok &= mat[i][j] == mat[n - i - 1][j];
				}
			}
		}

		puts(ok ? "Symmetric." : "Non-symmetric.");
	}
	
	return 0;	
}
