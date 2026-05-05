#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        string s; getline(cin, s);
        int k,n,m;cin>>k>>n>>m;
        vector<int>a(n);
        vector<int>b(m);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < m; i++){
            cin>>b[i];
        }
        int i = 0, j = 0;
        vector<int> ans;
        while(i < n || j < m){
            int c = 0;
            while(i < n && (a[i]==0 || a[i] <= k)){
                // cout<<a[i]<<" ";
                ans.push_back(a[i]);
                if(a[i]==0){
                    k++;
                }
                i++;
                c = 1;
            }
            while(j < m && (b[j]==0 || b[j] <= k)){
                // cout<<b[j]<<" ";
                ans.push_back(b[j]);
                if(b[j]==0){
                    k++;
                }
                j++;
                c= 1;
            }
            if(!c){
                cout<<-1<<endl;
                break;
            }
        }
        if(ans.size()==m+n){
            for(auto x: ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        // cout<<endl;

    }
    return 0;
}