#include<bits/stdc++.h>
using namespace std;
int m;
int f(int n, int w){
    if(n==0)return 1;
    if(n<0 || w < 0)return 0;
    int v1 = 0, v2 = 0;
    for(int i = 1; i <= m; i++){
        v1+=f(n-i,1);
        v1+=f(n-i,2);
    }
    return v1;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        m=n;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cout<<f(i,2)<<endl;
            ans+=f(i,2);
        }
        cout<<ans<<endl;
    }
    return 0;
}