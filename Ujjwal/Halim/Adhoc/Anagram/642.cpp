#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, vector<string>> m;
	string str;
	while(getline(cin, str)) {
		if(isupper(str[0])) break;
		string temp = "", inp;
		stringstream p(str);
		while(p >> inp) {
			temp += inp;
		}
		sort(temp.begin(), temp.end());
		m[temp].push_back(str);
		sort(m[temp].begin(), m[temp].end());
	}
	
	while(getline(cin , str)) {
		if(isupper(str[0])) break;
		sort(str.begin(), str.end());
		if((int)m[str].size() == 0) {
			puts("NOT A VALID WORD");
				
		} else {
			for(string s : m[str]) {
				puts(s.c_str());
			}
		}
		puts("******");
	}
}
