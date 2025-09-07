#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int g1=0,g2=0,g=0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            g=gcd(g,x);
        }
        int ans;
        if(g==1){
            ans = 0;
        }else if(gcd(g,n)==1){
            ans = 1;
        }else if(gcd(g,n-1)==1){
            ans = 2;
        }else{
            ans = 3;
        }
        cout<<ans<<endl;
    }
    return 0;
}