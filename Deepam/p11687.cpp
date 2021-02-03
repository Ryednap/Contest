#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void len(string x){
    if(x == "1"){
        return;
    }
    x = to_string(x.length());
    cnt++;
    len(x);
}

int main(){
    string x0;
    cin >> x0;
    while(x0 != "END"){
        len(x0);
        cout << cnt+1 << endl;
        cnt = 0;
        cin >> x0;
    }
}
