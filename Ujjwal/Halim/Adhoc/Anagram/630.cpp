#include <bits/stdc++.h>
using namespace std;

// Quite an easy problem with same concept as above group the strings according to the sorted form
// Complexity is O(nLogn) and O(N + M) complexity (same as adjacency list in graph) as the string length is 20.

int main() {
	int qq;
	scanf("%d",&qq);
	while( qq-- ) {
		int N ;
		scanf("%d", &N);
		map<string, vector<string>> m;
		cin >> ws;
		for(int i = 0; i < N; ++i) {
			string str;
			getline(cin, str);
			string temp = str;
			sort(temp.begin(), temp.end());
			m[temp].push_back(str);
		}
		
		string str;
		while(getline(cin , str)) {
			if(str == "END") break;
			printf("Anagrams for: %s\n", str.c_str());
			string temp = str;
			sort(str.begin(), str.end());
			vector<string> v = m[str];
			const int n = (int)v.size();
			if(n == 0) {
				printf("No anagrams for: %s\n", temp.c_str());
			} else {
				for(int i = 0; i < n; ++i) {
					printf("%3d) %s\n",i + 1, v[i].c_str());
				}
			}
		}
		if(qq) puts("");
	}
	return 0;
} 	
