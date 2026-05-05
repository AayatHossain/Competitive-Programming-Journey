#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> b(2e5+1,0);
        vector<vector<int>> a(n);
        for(int i = 0; i < n; i++){
            int k; cin>>k;
            for(int j = 0; j < k; j++){
                int x; cin>>x;
                b[x]++;
                a[i].push_back(x);
            }
        } 
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            int f= 1;
            for(auto x: a[i]){
                b[x]--;
                if(b[x]==0){
                    f=0;
                   
                }
            }
            if(f){
                ans=1;
                break;
                    
            }
            for(auto x: a[i]){
                b[x]++;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}