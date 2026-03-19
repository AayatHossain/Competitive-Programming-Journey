#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(32,0);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                if(a[i] & (1<<j)){
                    b[j]++;
                }
            }
        }
        int GCD = 0;
        for(int i = 0; i < 32; i++){
            
            GCD = gcd(b[i], GCD);
        }
        // for(auto x: b){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // cout<<GCD<<endl;
        vector<int> ans;
        for(int i = 1; i*i <= GCD; i++){
            if(GCD % i == 0){
                ans.push_back(i);
                if(GCD/i != i){
                    ans.push_back(GCD/i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(auto x: ans){
            cout<<x<<" ";
        }
        if(GCD==0){
            for(int i = 1; i <= n; i++){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        
    }
    return 0;
}