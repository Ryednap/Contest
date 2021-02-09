#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, qq;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &qq);
    while( qq-- ) {
        int l, r;
        scanf("%d %d", &l, &r);
        assert(r >= l);
        int ans = INT_MAX;
        for (int i = l; i <= r; ++i) {
            ans = std :: min(ans, v[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
