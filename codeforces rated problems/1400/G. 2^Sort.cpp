#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n,0);
        for(int i  =0 ;i < n; i++)cin>>a[i];
        for(int i = 0; i < n-1; i++){
            if(a[i ] < 2*a[i+1]){
                b[i]=1;
            }
        }
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(i < k-1){
                cnt += b[i];
            }else{
                cnt+=b[i];
                if(cnt==k)ans++;
                if(b[i-k+1]==1)cnt--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}