#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> b(31,0);
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            for(int j = 0; j <= 30; j++){
                if((x & (1<<j))){
                    b[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 30; i >= 0; i--){
            if(b[i]==n){
                ans += (1<<i);
            }
            else if(n - b[i] <= k){
                k-= n - b[i];
                ans += (1<<i);
            }
        }
        cout<<ans<<endl;
        // for(int i = 10; i >= 0; i--){
        //     cout<<b[i]<<" ";
        // }
    }
    return 0;
}