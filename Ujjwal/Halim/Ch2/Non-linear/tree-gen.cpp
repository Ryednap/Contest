// generating a tree in a simple way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = 1e6;
    puts("1 1000000");
    for(int i = 0; i < n; ++i) {
		printf("%d\n", rand(1, 100000));
	}
	return 0;
}
