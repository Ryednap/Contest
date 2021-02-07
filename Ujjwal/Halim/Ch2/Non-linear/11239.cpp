#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif
using pis =  pair<int, string>;
#define f first
#define s second


// Yeah a nice problem i like it but stil the toughness lies in string format input not on the idea of the code
// 2 min reading and thining
// 13 min coding
// 2 min debugging.

int main() {
	string str;
	while ( true ) {
		map<string, set<string> >  mapper;
		map<string, set<string> > count ;
		string prev = "";
		
		auto isKey = [] (string & s) {
			for(char ch : s) {
				if(isalpha(ch)) {
					if(islower(ch)) return false;
				} else if(isspace(ch)) continue;
				else return false;
			}
			return true;
		};
		
		while (getline(cin, str)) {
			if(str == "1") break;
			else if(str == "0") return 0;
			if(isKey(str)) {
				prev = str;
				mapper[str];
			} else if(prev != "") {
				mapper[prev].insert(str);
				count[str].insert(prev);
			}
		}
		
		vector<pair<int, string>> ans;
		for(auto p : mapper) {
			int total = 0;
			for(auto s : p.s) {
				int x = (int)count[s].size();
				if(x == 1) ++total;
			}
			ans.emplace_back(total, p.f);
		}
		
		auto cmp = [&] (const pis & p1, const pis & p2) {
			if(p1.f == p2.f) {
				return p1.s < p2.s;
			} else return p1.f > p2.f;
		};
		
		sort(ans.begin(), ans.end(), cmp);
		for(auto p : ans) {
			printf("%s %d\n", p.s.c_str(), p.f);
		}
		
	}
		
	return 0;
}



/* Special case for a proj no student
	UBQTS TXT
	LIVESPACE BLOGJAM
	philton
	aeinstein
	YOUBOOK
	j97lee
	sswxyzy
	j97lee
	aeinstein
	SKINUX
	1
	0

 * 
 * 
 */
