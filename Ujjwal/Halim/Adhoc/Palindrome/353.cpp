#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


bool Palindrome(string & str) {
	const int n = (int)str.length();
	for(int i = 0, j = n - 1; i <= j; ++i, --j) {
		if(str[i] != str[j]) return false;
	}
	return true;
}

int main() {
	string str;
	while( getline(cin, str) ) {
		set<string> ans;
		const int n = (int)str.length();
		for(int i = 0; i < n; ++i) {
			string maybe = "";
			for(int j = i ; j < n; ++j) {
				maybe += str[j];
				if(Palindrome(maybe)) ans.insert(maybe);
			}
			
		}
		printf("The string '%s' contains %d palindromes.\n", str.c_str(),(int)ans.size());
	}
	return 0;
}
