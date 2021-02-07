#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Easy level 1

// 3 min 19 sec to read and note and understand the problem
// 3 min 31 sec to code the solution
// 7 min 45 sec to verify the solution through manual testing (this is large).
// 4 WA : Reason : Again I assumed something
// I assumed supppose we have two trees "a c" and "ab" well i thought "ab" should some come before but because of space it may not be possible so
// i converted to a general form for sorting and it turned out to be wrong 

#define f first
#define s second

//using pss = pair<string, string>;

//string F (string & s) {
	//string res = "";
	//for(char ch : s) {
		//res += tolower(ch); // change here 1
	//}
	//return res;
//}

int main() {
	int qq; 
	scanf("%d", &qq);
	string str;
	getline(cin, str); // to clear of the blank line just after test_case number;
	getline(cin, str);

	while( qq -- ) {
		map<string, int> mapper;
		int total = 0;
		while( getline (cin, str) ) {
			if(str == "") break;
			//mapper[{F(str), str}]++;
			mapper[str]++;
			++total;
		}
		assert(total != 0);
		for(auto p : mapper) {
			printf("%s %.4Lf\n", p.f.c_str(), ((long double)p.s * 100) / total);
		}
		if(qq) puts("");
	}
		
	return 0;
}


/*
 * Checks made during debugging
 * The code seperates b/w test_cases
 * The comparison for string as for the case a b ac we need to generalise the comparison function
 * The output
 */
