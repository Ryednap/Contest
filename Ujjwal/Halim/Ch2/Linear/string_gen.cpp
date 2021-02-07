#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
	return rand()%(b - a + 1);
}
string rand_str(int a, int b) {
	int n = rand(a, b);
	string s = "";
	for(int i =  0; i < n; ++i) {
		s += rand(0, 25) + 'a';
	}
	return s;
}

int main(int argv, char **argc) {
	srand(atoi(argc[0]));
	puts("100");
	for(int _ = 100; _ >= 0; --_) {
		printf("%d %d\n", 100, rand(0, 99));
		for(int i = 0; i < 100; ++i) {
			printf("%d ", rand(1, 9));
		}
		puts("");
	}
	return 0;
}
