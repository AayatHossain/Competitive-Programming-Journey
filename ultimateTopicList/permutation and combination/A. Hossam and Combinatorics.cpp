#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int mx = LLONG_MIN;
        int mn = LLONG_MAX;
        for(int i = 0 ;i < n; i++){
            mx = max(mx,a[i]);
            mn = min(mn,a[i]);
        }
        int c1 = 0,c2 = 0;
        for(int i = 0; i < n; i++){
            if(a[i]==mx)c1++;
            if(a[i]==mn)c2++;
        }
        int ans = 0;
        if(mx==mn){
            ans = n*(n-1);
        }else{
            ans = 2*c1*c2;
        }
        
        cout<<ans<<endl;
        
        
    }
 
    return 0;
}