#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Unable to format :<

struct Game {
	string name;
	int n, g, c, gd,points;
	double p;
	
	Game() {}
	Game(string q) {
		name = q;
		n = g = c = gd = points = 0;
		p = -1.0;
	}
	
	void Played(int scored, int conceed){
		++n;
		g += scored;
		c += conceed;
		if(scored > conceed) points += 3;
		else if(scored == conceed) points ++;
	}
	void Calculate() {
		gd = g - c;
		if(n != 0) {
			p = (double)points / (n * 3) * 100;
		}
	}
	
	bool operator < (const Game & x ) const {
		if(points == x.points) {
			if(gd == x.gd) {
				if(g == x.g) {
					return name < x.name;
					
				} else {
					return g > x.g;
					
				}	
				
			} else {
				return gd > x.gd;
				
			}	
				
		} else  {
			return points > x.points;
		}
	}
	
	bool Equal(const Game & x) const {
		bool ok = true;
		ok &= points == x.points;
		ok &= gd == x.gd;
		ok &= g ==x.g;
		return ok;
	}
	void print() {
		printf("%s %d %d %d %d %d", name.c_str(), points, n , g, c, gd);
		if(p < 0) puts( " N/A");
		else printf(" %.2f\n", p);
	}
};

int main( ) {
	int t, g;
	int pad = 15;
	vector<vector<Game>> Final;
	
	while( scanf("%d %d",&t, &g) != EOF ) {
		if(t == 0 && g == 0) break;
		
		map<string, Game> team;
		for(int i = 0; i < t; ++i) {
			string s;
			cin >> s;
			team[s] = Game(s);
		}
		
		cin >> ws;
		for(int i = 0; i < g; ++i) {
			string t1, t2, buff;
			int a, b;
			cin >> t1 >> a >> buff >> b >> t2;
			team[t1].Played(a, b);
			team[t2].Played(b, a);
		}
		
		vector<Game> ans;
		for(auto shit : team) {
			shit.second.Calculate();
			ans.push_back(shit.second);
			pad = max(pad, (int)shit.first.length());
		}
		sort(ans.begin(), ans.end());
		Final.push_back(ans);
	}
	
	for(auto to : Final) {
		auto ans = to;
		int pos = 1;
		for(int i = 0; i < (int)ans.size(); ++i) {
			string space (pad - (int)ans[i].name.length(), ' ');
			printf("%d. %s", pos, space.c_str());
			ans[i].print();
			if(i != (int)ans.size() - 1 && !ans[i].Equal(ans[i + 1])) ++pos;
		}
		puts("");
	}		
	return 0;	
}
