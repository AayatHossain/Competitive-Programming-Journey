#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        string s;cin>>s;
        // cout<<s;

        int m = s.size();
        vector<pair<int,int>> ans;
        
        
        vector<pair<int,int>> dl;
        vector<pair<int,int>> l;
        for(int i = 0; i < n; i++){
            if(s[i]=='0'){
                dl.push_back({a[i], i});
               
            }
        }
      
        for(int i = 0; i < m; i++){
            if(s[i]=='1'){
                l.push_back({a[i], i});
            }
        }
        // cout<<ans.size()<<endl;
        sort(l.begin(), l.end());
        sort(dl.begin(), dl.end());
        int count = 1;
        for(int i = 0; i < dl.size(); i++){
            ans.push_back({dl[i].second, count});
            count++;
        }
        for(int i = 0; i < l.size(); i++){
            ans.push_back({l[i].second, count});
            count++;
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i<n; i++){
            cout<<ans[i].second<<" ";
        }
        cout<<endl;

    }
    return 0;
}