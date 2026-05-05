#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
           int ans = (1 << 30) - 1;
        
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i] != i){
                ans &= a[i];
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}