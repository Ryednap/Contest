#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// So here comes the application of the prev variable which i recommend should be init with some value that can never occur in the input.

int main( ) {
	string str;
	map<char, char> mapper = {{'B', '1'},{'F', '1'},{'P', '1'},{'V', '1'},{'C', '2'},{'G', '2'},
		{'J', '2'},{'Q', '2'},{'S', '2'},{'K', '2'},{'X', '2'},{'Z', '2'},{'D', '3'},{'T', '3'},{'L', '4'},{'M', '5'},
		{'N', '5'},{'R', '6'}
	};
	while(cin >> str) {
		string ans = "";
		char prev = ' ';
		for(char ch : str) {
			if(mapper.find(ch) != mapper.end() ) { // the ch exists in the mapper
				if(mapper[ch] != prev) { // if it's not equal to the previous.
					prev =  mapper[ch];
					ans += prev;
				}
			} else prev = ' ';
		}
		puts(ans.c_str());
	}
	return 0;	
}
