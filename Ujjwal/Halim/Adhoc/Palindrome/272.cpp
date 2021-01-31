#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	bool ok = false;
	while(getline(cin, str)) {
		string ans =  "";
		for(char & ch : str) {
			if(ch == '"') {

				if(!ok) ans += "``";
				else ans += "''";
				ok ^= 1;
				
			} else ans += ch;
		}
		puts(ans.c_str());
	}
	return 0;
}

