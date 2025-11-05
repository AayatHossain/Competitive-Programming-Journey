#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<pair<int,int>> b;
        for(int i = 0; i < n; i++){
            if(a[i] > 0){
                int s = 0;
                while(i<n && a[i] > 0){
                    s+=abs(a[i]);
                    i++;
                }
                b.push_back({s,1});
                i--;
            }else{
                int s = 0;
                while(i<n && a[i] < 0){
                    s+=abs(a[i]);
                    i++;
                }
                b.push_back({s,0});
                i--;
            }
        }
        int ans = LLONG_MIN;
        // if(b.size()==2 && b[0].second==1 && b[1].second==0){
        //     ans = 0;
        //     for(auto x: b){
        //         ans+=x.first;
        //     }
        //     cout<<ans<<endl;
        //     continue;
        // }
        int s = 0;
        for(int i = 0; i < b.size();i++){
            if(b[i].second==1 || (b[i].second==0 && i==b.size()-1)){
                s+=b[i].first;
            }else{
                ans = max(ans, s + b[i].first);
            }
        }
        ans = max(ans,s);
        cout<<ans<<endl;
    }
    return 0;
}