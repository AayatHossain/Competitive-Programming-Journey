#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        vector<int> c(n);
        for(int i = 0; i < n; i++){
            c[i] = a[i] - b[i];
        }
        sort(c.begin(),c.end());


        vector<pair<int,int>> sorted(n);
        for(int i = 0; i < n; i++){
            sorted[i] = {a[i]-b[i], i};
        }

        int mx = 0;
        vector<int> cnt(n);
        sort(sorted.begin(),sorted.end());
        for(int i = 0; i < n; i++){
            int v = sorted[i].first;
            int ub = upper_bound(c.begin(),c.end(),v) - c.begin();
            ub--;
            if(ub >= 0){
                cnt[sorted[i].second] = ub+1;
                mx = max(mx, cnt[sorted[i].second]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(cnt[i]==mx){
                ans.push_back(i+1);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<'\n';
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
}