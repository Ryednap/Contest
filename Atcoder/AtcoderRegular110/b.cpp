#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((int)x.size())
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

void solve(){
	int N;
	scanf("%d",&N);
	
	string S = "110110110";
	string T; cin >> T;
	if(N == 1){
		if(T == "1") printf("%llu",(ll)2e10);
		else printf("%llu",(ll)1e10);
		return ;
	}
	
	vector<int> v;
	for(int i = 0; i < sz(S); ++i){
		int a = i, b = 0;
		while(S[a] == T[b] && a < sz(S) && b < sz(T) ){
			++a, ++b;
		}
		if(a == sz(S) || b == sz(T)) v.push_back(i);
	}
	
	if(sz(v) == 0){
		puts("0");
		return ;
	}
	
	string check = "110";
	string make = "";
	for(int i = 0; i < 3*N; ++i) make += check;
	
	bool ok = true;
	for(int i = v.front();  i < N; ++i){
		if(make[i] != T[i]){
			ok = false;
			break;
		}
	}
	
	if(ok == false){
		puts("0");
		return;
	}
	
	for(int i = sz(S) - 1; i >= 0 ; --i){
		int a = i, b = sz(T) - 1;
		while(S[a] == T[b] && a >= 0 && b >= 0){
			--a , -- b;
		}
		if(a < 0 || b < 0){
			v.push_back(i);
			break;
		}
	}
	
	int front_gap = v.front();
	int back_gap = sz(S) - v.back() - 1;
	int lap = v[1] - v[0];
	//debug() << owo(front_gap) owo(back_gap) owo(lap) owo(v);
	long long answer = 3e10 - front_gap - back_gap;
	long long res = 0;
	if(lap <= (int)T.length()){ // gap
		int gap =(int)T.length() - lap;		
		answer -= (int)T.length();
		
		res = answer/( (ll)sz(T) - gap) + 1;
		//debug() << owo(res) owo(answer) owo(gap);
	} else { // overlap
		int gap = lap - sz(T);
		res = answer/ ((ll)sz(T) + gap);
	}
	
	printf("%lld",res);
	
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



