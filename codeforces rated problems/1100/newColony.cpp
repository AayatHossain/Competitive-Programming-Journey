#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i  = 0; i < n; i++)cin>>a[i];
        int c = 0;
        int ans = -1;
        for(int i = 0; i < k; i++){
            int f = 0;
            for(int j = 0; j < n-1; j++){
                // if(i==1){
                //     cout<<a[j]<<" "<<a[j+1]<<endl;
                // }
                if(a[j] < a[j+1]){
                    c ++;
                    a[j]++;
                    f = 1;
                    ans = j;
                    // cout<<c<<" "<<ans<<endl;
                    break;
                }
            
            }
            // for(auto x: a){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            if(c >= k){
                break;
            }
            if(!f){ans = -1;break;}
        }
        if(ans != -1)ans++;
        cout<<ans<<endl;
    }
    return 0;
}