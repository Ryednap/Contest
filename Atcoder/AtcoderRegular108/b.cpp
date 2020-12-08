#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// pretty easy problem just a care implementation
// lower medium level
// The idea is we can have lot's of fox word one after another. 
// just make a stack . whenever we encounter (consecutive) 'f' or 'o' just push it after that clear the stack
// Now when we encounter an x we know that we have chance to make one "fox" word if possible count it and then pop both the character else we know that there has been
// break so clear the stack. pretty easy problem. Now the answer is N - 3 * count. 

void solve(){
	int N; scanf("%d",&N);
	string str; cin >> str;
	
	stack<char> s;
	int ans = 0;
	for(int i = 0; i < N; ++i){
		char ch = str[i];

		if(ch == 'f' || ch == 'o'){
			s.push(ch);
		
		} else if( ch == 'x'){
			if(sz(s) >= 2){
				char a = s.top(); s.pop();
				char b = s.top(); s.pop();
				if(a == 'o' && b == 'f') ++ans;
				else s = stack<char>();
			} else s = stack<char>();
				
		} else s = stack<char>();
	}
	printf("%d",N - ans * 3);
		
}


int main(){
	int tt;
	//scanf("%d",&tt);
	tt = 1;
	for(int _ = 1;_ <=tt;++_ ){
		solve();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}



