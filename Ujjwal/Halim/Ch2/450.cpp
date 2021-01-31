#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


static inline void ltrim(string & s) {
	s.erase(s.begin(), std :: find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !(std :: isspace(ch));
	}));
}

static inline void rtrim(string & s) {
	s.erase(std :: find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return (!std :: isspace(ch));
	}).base(), s.end());
}

static inline void trim(string & s) {
	ltrim(s);
	rtrim(s);
}

struct Information {
	string t, first, l;
	string home, dept, hphone;
	string box, wphone;
	
	Information() {}
	Information(string a, string b, string c, string d, 
		string e, string f, string g, string h) : t(a), first(b), l(c), home(d), dept(e), hphone(f), box(g), wphone(h) {};
	
	bool operator < (const Information & i) const {
		return l < i.l;
	}
	void print() {
		printf("%s %s %s\n", t.c_str(), first.c_str(), l.c_str());
		printf("%s\n", home.c_str());
		printf("Department: %s\n", dept.c_str());
		printf("Home Phone: %s\n", hphone.c_str());
		printf("Work Phone: %s\n", wphone.c_str());
		printf("Campus Box: %s\n", box.c_str());
	}
};

	
int main( ) {
	int n;
	while(scanf("%d", &n) != EOF) {
		cin >> ws;
		vector<Information> ans;
		for(int i = 0; i < n; ++i) {
			string dpt, s;
			getline(cin, dpt);
			trim(dpt);
			
			while( getline(cin, s) ) {
				if(s == "") break;
				stringstream ss(s);
				vector<string> v;
				string inp;
				
				while( getline(ss, inp, ',')) {
					trim(inp);
					v.push_back(inp);
				}
				Information info(v[0], v[1], v[2], v[3], dpt, v[4], v[6], v[5]);
				ans.push_back(info);
			}
		}
		sort(ans.begin(), ans.end());
		auto printline = []() {
			puts("----------------------------------------");
		};
		
		for(auto p : ans) {
			printline();
			p.print();
		}
	}
	
	return 0;	
}
