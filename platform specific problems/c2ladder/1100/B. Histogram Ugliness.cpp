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
        int ans = 0;
        if(n==1){
            ans = a[0];
        }else{
            for(int i = 0; i < n; i++){
                if(i==0){
                    if(a[i] > a[i+1]){
                        ans += a[i] - a[i+1];
                        a[i] = a[i+1];
                    }
                }else if(i==n-1){
                    if(a[i] > a[i-1]){
                        ans += a[i] - a[i-1];
                        a[i] = a[i-1];
                    }
                }else{
                    if(a[i] >= a[i+1] && a[i] >= a[i-1]){
                        int mx = max(a[i-1], a[i+1]);
                        ans += a[i] - mx;
                        a[i] = mx;
                    }
                }
            }
            // cout<<ans<<endl;
            // for(auto x: a){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            for(int i = 1; i < n; i ++){
                ans +=abs( a[i] - a[i-1]);
                
            }
            ans+=a[0];
            ans+=a[n-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}