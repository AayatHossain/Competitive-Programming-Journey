#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int c = 0;
        while(n > 0){
            int r = sqrt(1+24*n);
            int h = (r - 1)/6;
            if(h==0)break;
            c++;
            int cards = h*(h+1) + (h*(h-1))/2;
            n -= cards;
        }
        cout<<c<<endl;
    }
    return 0;
}