#include <bits/stdc++.h>
using namespace std;

bool Palindrome(string & str) {
	const int n = (int)str.length();
	for(int i = 0, j = n - 1; i <= j; ++i, --j) {
		if(str[i] != str[j]) return false;
	}
	return true;
}

int main() {
	string str;
	while(getline(cin, str)) {
		if(str == "DONE") break;
		string s = "";
		for(char ch : str) {
			if(isalpha(ch)) s += tolower(ch);
		}
		if(Palindrome(s)) printf("You won't be eaten!\n");
		else puts("Uh oh..");
	}
	return 0;
}
