#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif
#define sz(x) ((int)x.size())

// A medium problem based on sliding window technique + BS = O(n(logn)^2) OR sliding window + two pointer = O(nlogn)
// This problem is optimization as it uses two pointer
// The main problem is with identifying words as it may not be clear from the statement and also with respect index management in two pointer
int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	cin >> ws;
	while( qq-- ) {
		string str, inp;
		vector<string> v;
		while (getline(cin, str) && str != "END") {
			stringstream ss(str);

			while( ss >> inp) {
				
				string word = "";
				for(char ch : inp ) {
					if(isalpha(ch)) word += ch;
					else if(word != ""){
						v.push_back(word);
						word = "";
					}
				}
				if(word != "") v.push_back(word);
			}
		}
		
		auto My_max = [&] (const pair< int, int > & a, const pair< int, int > & b) {
			int x = a.second - a.first;
			int y = b.second - b.first;
			if(x <= y) return a;
			else return b;
		};
		
		set<string> s ( v.begin(), v.end());
		
		pair<int, int> ans;
		map<string, int> mapper;
		const int n = sz(v);
		const int m = sz(s);
		for(int i = 0, j = 0; i < n; ++i) { // problems faced is here with indices not with the concept. Concept was clear from beg. that it is sliding window technique
			while( j < n && sz(mapper) != m) {
				mapper[v[j]]++;
				++j;
			}
			
			if(sz(mapper) == sz(s)) {
				if(ans.first == 0 && ans.second == 0) ans = make_pair(i, j);
				else ans = My_max(ans, make_pair(i, j));
			}
			mapper[v[i]]--;
			if(mapper[v[i]] == 0) mapper.erase(v[i]);
		}
		printf("Document %d: %d %d\n", ++tt, ans.first + 1, ans.second);
	}
	return 0;
}


