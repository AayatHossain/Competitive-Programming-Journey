#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        vector<int> a;
        for(int i = 0; i < n; i++){
            char x; cin>>x;
            if(x=='*')a.push_back(i);
        }
        int ans = 0;
        if(a.size()==1){
            ans = 1;
        }else{
            ans += 2;
            int m = a.size();
            int i = 0;
            // for(auto x: a){
            //     cout<<x<<endl;
            // }
            // int c = 0;
            while(i < m){
                int v = a[i] + k;
                int ub = upper_bound(a.begin(), a.end(), v) - a.begin();
                ub--;
                
                if(ub >= m-1){
                    break;
                }else{
                    ans++;
                    i = ub;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}