#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
   return rand() % (b - a + 1);
}

int main (int argc , char ** argv) {
    srand(atoi(argv[1]));
    
    int n = rand(1, 1000);
    printf("%d\n", n);
    for(int i = 0; i < n;  ++i) {
        printf("%d ", rand(1, 100000));
    }
    puts("");
    int qq = rand(1, 1000);
    printf("%d\n", qq);
    for(int i = 0; i < qq; ++i) {
        int l = rand(1, n / 2);
        int r = rand(n / 2, n );
        printf("%d %d\n", l, r);
    }
    puts("");
    return 0;
}
