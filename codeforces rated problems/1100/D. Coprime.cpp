#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a;
        
        map<int,int> m;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            m[x] = i+1;
        }
        for(auto x: m){
            a.push_back({x.first, x.second});
        }
        int ans = INT_MIN;
        for(int i = 0; i < a.size();i++){
            int x = a[i].first;
            for(int j = i; j < a.size(); j++){
                int y = a[j].first;
                if(gcd(x,y)==1){
                    ans = max(ans, a[i].second+a[j].second);
                }
            }
        }
        if(ans==INT_MIN)ans=-1;
        cout<<ans<<endl;
        
    }
    return 0;
}