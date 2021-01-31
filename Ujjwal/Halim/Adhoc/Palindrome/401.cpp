#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
#include "uj.h"
#endif

map<char, char> m1 = { {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'M', 'M'}, {'O', 'O'},  {'S', '2'} , {'T', 'T'}, {'U', 'U'}, 
	{'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'8', '8'}};
map<char, char> m;

bool Palindrome(string & str) {
	const int n = (int)str.length();
	for(int i = 0, j = n - 1; i <= j; ++i, --j) {
		if(str[i] != str[j]) return false;
	}
	return true;
}

bool Mirror(string & str) {

	string temp = "";
	for(char ch : str) {
		temp += m[ch];
	}
	reverse(temp.begin(), temp.end());
	return temp == str;
}
	

int main( ) {
	string str;
	for(auto p : m1) {
		m[p.second] = p.first;
		m[p.first] = p.second;
	}
		
	while( getline(cin , str) ) {
		bool a = Palindrome(str);
		bool b = Mirror(str);
		string ans = "";
		if(a & b) ans = "is a mirrored palindrome";
		else if(a) ans = "is a regular palindrome";
		else if(b) ans = "is a mirrored string";
		else ans = "is not a palindrome";
		
		printf("%s -- %s.\n", str.c_str(), ans.c_str());
		puts("");
	}
	return 0;
}
