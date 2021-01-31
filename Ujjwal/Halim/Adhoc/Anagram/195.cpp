#include <bits/stdc++.h>
using namespace std;


// A nice problem 

/* First attempt :- WA (because of the missing one part of the question (An upper case relative to the lower case comes before . i.e for AaB trivial
 * sort will show ABa < AaB which from the problem statement wrong
 * O(N!) complexity and O(N) space
 */

int main() {
	int qq;
	scanf("%d",&qq);
	while(qq -- ) {
		string str;
		cin >> str;
		vector<char> v(str.begin(), str.end());
		sort(v.begin(), v.end());
		set<string> ans;
		do {
			string t = "";
			for(char c : v) t += c;
			ans.insert(t);
		} while(next_permutation(v.begin(), v.end()));
		
		auto cmp = [](const string & a, const string & b) {
			int i = 0, j = 0;
			while(i != (int)a.length() || j != (int)b.length()) {
				char c1 = a[i], c2 = b[j];
				char c11 = tolower(a[i]), c22 = tolower(b[j]);
				bool f = isupper(c1), s = isupper(c2);
				if(c11 == c22) {
					if(f && !s) return true;
					if(s && !f) return false;
				} else if(c11 < c22) return true;
				else return false;
				++i, ++j;
			}
			return true;
		};
		vector<string> res (ans.begin(), ans.end());
		sort(res.begin(), res.end(), cmp);
		for(string x : res) {
			puts(x.c_str());
		}
	}
	return 0;
}
