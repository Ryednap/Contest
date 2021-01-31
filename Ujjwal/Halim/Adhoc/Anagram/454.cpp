#include <bits/stdc++.h>

/* One assumption as it was not clear from the statement. Suppose we have multiple same words then we need to include
 * Complexity : O(N^2) (for pairs). O(N^2) space
 * Just do the same group the words.
 */

using namespace std;
#define s second
#define f first
int main( ) {
	int qq;
	scanf("%d",&qq);
	cin >> ws;
	while( qq -- ) {
		string str;
		map<string, vector<string>> m;
		while(getline(cin, str)) {
			if(str == "") break;
			string temp = "", ip;
			stringstream p(str);
			while( p >> ip) {
				temp += ip;
			}
			sort(temp.begin(), temp.end());
			m[temp].push_back(str);
		}
		
		vector<pair<string, string>> ans;
		for(auto p : m) {
			const int n = (int)p.s.size();
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					string a = p.s[i];
					string b = p.s[j];
					if(a > b) swap(a, b);
					ans.push_back( make_pair(a, b));
				}
			}
		}
		sort(ans.begin(), ans.end());
		for(auto p : ans) {
			printf("%s = %s\n", p.f.c_str(), p.s.c_str());
		}
		if(qq != 0) puts("");
	}
	return 0;
}
