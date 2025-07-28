#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        vector<pair<pair<int,int>, int>> ans;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                int l = i;
                int r = l+1;
                while(a[r] != b[i]){
                    r++;
                }
                for(int j = r; j > l; j--){
                    a[j] = a[j-1]; 
                }
                a[l] = b[i];
                ans.push_back({{l+1,r+1},r-l});
                // cout<<l+1<<" "<<r+1<<" "<<r-l <<endl;
            }
        }
        cout<<ans.size()<<endl;
        for(auto x: ans){
            cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
        }
    }
    return 0;
}