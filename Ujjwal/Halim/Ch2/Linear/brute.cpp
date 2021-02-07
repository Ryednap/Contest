#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while( scanf("%d",&n)) {
		if(n == 0) break;
		string arr[n];
		for(int i= 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		sort(arr, arr + n);
		string ans = "";
		do {
			string  maybe = "";
			for(int i = 0; i < n; ++i) {
				maybe += arr[i];
			}
			ans = max(ans, maybe);
			
		} while (next_permutation(arr, arr + n));
		puts(ans.c_str());
	}
	return 0;
}
