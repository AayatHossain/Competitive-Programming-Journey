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
        int cg = 0;
        for(int i = 0; i < n; i++){
            int currentbest = 0;
            int index = -1;
            for(int j = 0; j < n; j++){
                if(a[j]==-1)continue;   
                if(gcd(cg,a[j]) >= currentbest){
                    currentbest = gcd(cg,a[j]);
                    index = j;
                }
            }
            ans.push_back(a[index]);
            a[index] = -1;
            cg = currentbest;
        }
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}