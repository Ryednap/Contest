#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// string heavy problem but the complexity is Same as O(nlogn)

static inline void ltrim (string & s) {
	s.erase(s.begin(), find_if (s.begin(), s.end(), [] (unsigned char ch) {
		return !isspace(ch);
	}));
}
static inline void rtrim(string & s) {
	s.erase(find_if(s.rbegin(), s.rend(), [] (unsigned char ch) {
		return !isspace(ch);
	}).base(), s.end());
}

static inline void trim(string & s) {
	ltrim(s); rtrim(s);
}

static inline void Transform(string & s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
}

int main() {
	string str;
	while( true ) {
		map<string, int> mapper;
		int lambda = 0;
		while( getline(cin, str) ) {
			if(str == "****END_OF_TEXT****") break;
			else if(str == "****END_OF_INPUT****") return 0;
			
			stringstream ss(str);
			string s;
			while( ss >> s) {
				trim(s);
				Transform(s);
				string tobe = "";
				for (char ch : s) {
					if(isalnum(ch)) { // missed here for first time forgot that digits are also allowed
						tobe += ch;
					}
				}
				if(tobe != "") {
					++lambda;
					mapper[tobe]++;
				}
			}
		}
		
		
		long double ET = 0, Emax = (long double)log10(lambda);
		for(auto p : mapper) {
			ET += p.second * ((long double)log10(lambda) - (long double)log10(p.second));
		}
		ET /= lambda;
		int ans = (ET * 100 )/ Emax;
		
		printf("%d %.1Lf %d\n", lambda, ET, ans);
	}
		
	return 0;
}


