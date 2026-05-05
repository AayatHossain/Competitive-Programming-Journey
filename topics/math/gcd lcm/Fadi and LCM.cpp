#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int x; cin>>x;
    int mn = INT_MAX;
    int a,b;
    for(int i = 1; i*i <= x; i++){
        int v = lcm(i, x/i);
        if(v==x){
            int mn2 = min(i, x/i);
            if(mn2 < mn){
                a = i; b= x/i;
            }
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}