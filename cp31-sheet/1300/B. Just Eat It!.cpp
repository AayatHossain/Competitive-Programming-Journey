#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> p(n);
        int f = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(i==0)p[0]=a[i];
            else p[i]=p[i-1]+a[i];
            if(a[i]<0)f=1;
        }
        int mn = 0;
        int mi = -1;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, p[i] - mn);
            if(p[i]<=mn){
                mn = p[i];
                mi = i;
            }
        }
        // cout<<ans<<endl;
        if(ans >= p[n-1] && f==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
    return 0;
}