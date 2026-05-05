#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int n,l; cin>>n>>l;
        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++){
            int x,r; cin>>x>>r;
            int prev = max(x-r,0LL);
            int next = x+r;
            a.push_back({prev,next});
        }
        sort(a.begin(),a.end());
        vector<pair<int,int>> b;
        
        if(a.size()>=1){
            pair<int,int> curr = a[0];
            for(int i = 1; i < a.size(); i++){
                if(a[i].first <= curr.second ){
                    curr.second = max(curr.second, a[i].second);

                }else{
                    b.push_back(curr);
                    curr = a[i];
                }
            }
            b.push_back(curr);
        }
        int f = 0;
        for(auto x: b){
            if(x.first == 0 && x.second >= l){
                f = 1;
                break;
            }
        }
        if(f)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
    

    return 0;
}