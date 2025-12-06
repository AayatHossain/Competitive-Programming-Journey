#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i =0;i < n; i++){
            cin>>a[i];
        }
        vector<int> ans;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            mx = max(mx,a[i]);
        }
        for(int i = 0; i < n; i++){
            if(a[i]==mx){
                ans.push_back(mx);
                a[i]=-1;
            }
        }
        
        for(int i = 0; i < n; i++){
            int mx2 = 1;
            for(int j = 0; j < n; j++){
                if(a[j]==-1)continue;
                mx2 = max(mx2,gcd(a[j],mx));
            }
            for(int j = 0; j < n; j++){
                if(a[j]==-1)continue;   
                if(gcd(a[j],mx)==mx2){
                    ans.push_back(a[j]);
                    a[j]=-1;
                    break;
                }
            }
        }
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<gcd(948,14)<<endl;
    }
    return 0;
}