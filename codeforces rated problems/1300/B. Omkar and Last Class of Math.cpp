#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        
        int l = INT_MAX;
        int a,b;
        for(int i = 1; i*i <= n; i++){
            if(n%i==0){
                int j = n-i;
                int nl = lcm(i,j);
                // cout<<i<<" "<<j<<" "<<nl<<endl;
                if(nl < l){
                    l = nl;
                    a = i; b = j;
                }
                
                int ni = n/i;
                j = n-ni;
                nl = lcm(ni,j);
                if(nl < l && j!=0){
                    l = nl;
                    a = ni, b = j;
                }
            }
        }
        cout<<a<<" "<<b<<endl;
    }
}