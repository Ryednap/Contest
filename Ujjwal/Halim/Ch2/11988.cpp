#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Why we need linked list ? if we maintain a string and then add the string everytime we switch posn then the total compleixty roughly becomes O(n^2) in
// the worst case. Hence to avoid such thing we maintain a linked list and instead of bogus adding we just append it to the linked list as O(1) insertion
// time is the best.

int main( ) {
	string str;
	while( getline(cin, str) ) {
		list<string> ans;
		string back = "" ,front = "";
		bool home = false;
		for(char & ch : str) {
			if(ch == ']') home = false;
			else if(ch == '[') home = true;
			
			if(ch == '[' || ch == ']') {
				ans.push_front(front);
				ans.push_back(back);
				front = "", back = "";
				
			} else if(home) front += ch;
			else back += ch;
		}
		ans.push_front(front);
		ans.push_back(back);
		string answer = "";
		for(auto s : ans) {
			answer += s;
		}
		puts(answer.c_str());
	}			
	return 0;	
}
