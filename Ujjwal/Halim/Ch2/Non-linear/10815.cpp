#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Easy problem

int main() {
	string str, inp;
	set<string> s;
	while (getline(cin, str)) {

		stringstream ss(str);
		while( ss >> inp) {
			 string word = "";
			 for(auto ch : inp) { // Note this is a common sub-routine when you see following statement problem : Word is a consecutive sequence of alpha
				 if(isalpha(ch)) word += tolower(ch);
				 else {
					 if(word != "") s.insert(word);
					 word = "";
				 }
			 }
			 if(word != "") s.insert(word);
		}
	}
	for(auto ans : s) {
		puts(ans.c_str());
	}
			
	return 0;
}


