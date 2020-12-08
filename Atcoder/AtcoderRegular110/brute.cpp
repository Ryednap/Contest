#include <bits/stdc++.h>
#define task        "735C"
#define REP(i,a,b)   for(int (i) = (a); i <= (b); ++i)
#define FOR(i,a,b)   for(int (i) = (a); i >= (b); --i)
#define MAX(a,b)    ((a)>(b)?(a):(b))
#define ll  long long

using namespace std;
ll 	n;

void home(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void enter(){
    cin>>n;
}

int tinh(ll n){
    if (n==2) return 1;
    if (n==3) return 2;
    ll tmp = n>>1;
    return MAX(tinh(tmp), tinh(n-tmp)) + 1;
}

void lam(){
    if (n==2){cout<<1; return; }
    if (n==3){cout<<2; return; }
    ll a = 2; 
    ll b = 3; 
    int res = 2; ll c;
    while(true){
        ++res;
        c = a + b;
        if (c > n) break;
        a = b;
        b = c;
    }
    cout<<res-1;
}

int main()
{
    home();
    enter();
    lam();
}
