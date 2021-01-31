#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A bit messy for the beginning altough easy problem.
// **Note** :- Generally it's not recommended to use double for comparison , but division by 2 is not any issue because we get like x or x.5 so we can 
// compare , if possible try to avoid double comparison, that's why i said messy. (I mean i tried to avoid all the percentage calc but ended up comparing
// double with /2)

// O(1)

int main( ) {
	int qq, tt = 0;
	scanf("%d",&qq);
	while( qq-- ) {
		int a, b, c, d;
		array<int, 3> test;
		scanf("%d %d %d %d",&a, &b, &c, &d);
		for(int i = 0; i < 3; ++i) {
			scanf("%d", &test[i]);
		}
		sort(test.begin(), test.end(), greater<int>());
		double scored = a + b + c + d + (test[0] + test[1])/2.0;
		
		char grade;
		if(scored >= 90 ) grade = 'A';
		else if(scored >= 80 ) grade = 'B';
		else if(scored >= 70 ) grade = 'C';
		else if(scored >= 60 ) grade = 'D';
		else grade = 'F';

		printf("Case %d: %c\n", ++tt, grade);
	}

	return 0;	
}
