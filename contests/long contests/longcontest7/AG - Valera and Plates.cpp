#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,b,p;cin>>n>>b>>p;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        if(x==1){
            c1++;
        }else{
            c2++;
        }
    }
    int ans = 0;
    if(c1 <= b){
        b -= c1;
    }else{
        ans +=(c1-b);
        b = 0;
    }
    int total = b+p;
    // cout<<c1<<endl;
    // cout<<ans<<endl;
    // cout<<total<<endl;
    if(c2 > total){
        ans += (c2- total);
    }
    cout<<ans<<endl;
    return 0;
}