#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const double epsilon = 1e-6;



bool Equal(float a, float b)
{
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool Greater(float a, float b)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool Less(float a, float b)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main() {
	
	
	int p, g;
	scanf("%d %d", &p, &g);
	map<string, double> vote;
	for(int i = 0; i < p ; ++i) {
		string s; 
		cin >> s >> vote[s];
	}
	auto Comp = [&] (string & s) {
		if(s == "<") return true;
		else if(s == ">") return true;
		else if(s == ">=") return true;
		else if(s == "<=") return true;
		else if(s == "=") return true;
		else return false;
	};
	
	auto Check = [&] (double a, double b, string & c) {
		if(c == "<") return Less(a, b);
		if(c == "<=") return Less(a, b) || Equal(a, b);
		if(c == ">=") return Greater(a, b) || Equal(a, b);
		if(c == ">") return Greater(a, b) ;
		else return Equal(a, b);
	};
	cin >> ws;
	for (int i = 0; i < g; ++i) {
		string str, inp, which = "";
		int n = 0;
		double total = 0;
		getline (cin, str);
		stringstream ss(str);
		while( ss >> inp) {
			if(Comp(inp)) {
				which = inp;
			} else if(which != "") {
				n = stoi(inp);
				
			} else if(inp != "+"){
				total += vote[inp];
			}
		}
		
		bool ans = Check(total, n, which);
		printf("Guess #%d was %s.\n", i + 1, ans ? "correct" : "incorrect");
	}
	return 0;
}


