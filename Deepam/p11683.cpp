#include<bits/stdc++.h>
using namespace std;
int main(){
    int h, l;
    while(scanf("%d %d", &h, &l) != EOF){
        if(h == 0){break;}
        int count = 0, lastH = h, prev;
        while(l--){
            int temp;
            scanf("%d", &temp);
            if(lastH > temp){
                count += lastH-temp;
            }
            lastH = temp;
        }
        printf("%d\n", count);
    }
    return 0;
}
