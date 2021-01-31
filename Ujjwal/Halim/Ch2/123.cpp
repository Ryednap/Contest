#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

static inline void ltrim(std :: string & s) {
	s.erase(s.begin(), std :: find_if(s.begin(), s.end(), [] (unsigned char ch)  {
		return !std :: isspace(ch);
	}));
}

static inline void rtrim(std :: string & s) {
	s.erase(std :: find_if(s.rbegin(), s.rend(), [] (unsigned char ch ) {
		return !std :: isspace(ch);
	}).base(), s.end());
}

static inline void trim(std :: string & s) {
	ltrim(s);
	rtrim(s);
}

static inline std :: string Capitalize(std :: string s) {
	std :: transform(s.begin(), s.end(), s.begin(), :: toupper);
	return s;
}

static inline std :: string  Smallize(std :: string s) {
	std :: transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

struct Dict {
	string key, s;
	pair<int, int> index;
	Dict() {}
	Dict(string a, string b,pair<int, int> i) : key(a), s(b), index(i) {}
	
	bool operator < (const Dict & D) const {
		if(key == D.key) {
			if(index.first == D.index.first) return index.second < D.index.second;
			else return index.first < D.index.first;
		} else return key < D.key;
	}
};

int main() {
	map<std :: string, bool> ignore;
	std :: string str;
	while( getline(cin, str) ) {
		if(str == "::") break;
		trim(str);
		str = Smallize(str);
		ignore[str] = true;
	}
	
	std :: vector<Dict> ans;
	int cnt = 0;
	while( getline(cin, str)) {
		std :: stringstream ss(str);
		std :: string inp;
		std :: vector<std :: string> temp;
		while( ss >> inp ) {
			trim(inp);
			inp = Smallize(inp);
			temp.push_back(inp);
		}
		
		for(int i = 0; i < (int)temp.size(); ++i) {
			std :: string s = temp[i];
			
			if(!ignore[s]) {
				s = Capitalize(s);
				std :: string res = "";
				for(int j = 0; j < (int)temp.size(); ++j) {
					if(i != j) {
						res += temp[j] + " ";
					} else res += s  + " " ;
				}
				ans.push_back(Dict(s, res, make_pair(cnt, i)));
			}
		}
		++cnt;
	}
	std :: sort(ans.begin(), ans.end());
	for(auto & d : ans) {
		trim(d.s);
		puts(d.s.c_str());
	}
	return 0;
}
				
