#include <bits/stdc++.h>
using namespace std;

bool Palindrome(string & str) {
	const int n = (int)str.length();
	for(int i = 0, j = n - 1; i <= j; ++i, --j) {
		if(str[i] != str[j]) return false;
	}
	return true;
}

bool Square(int n) {
	int x = sqrt(n);
	return x * x == n;
}

int main () {
	int qq, tt = 0;
	scanf("%d",&qq);
	while(qq -- ) {
		string str;
		cin >> ws;
		getline(cin, str);
		string s = "";
		for(char ch : str) {
			if(isalnum(ch)) s += tolower(ch);
		}
		printf("Case #%d:\n", ++tt);		
		const int n = (int)s.length();
		if(Square(n) && Palindrome(s)) {
			printf("%d\n",(int)sqrt(n));
		} else puts("No magic :(");
	}
	return 0;
}
