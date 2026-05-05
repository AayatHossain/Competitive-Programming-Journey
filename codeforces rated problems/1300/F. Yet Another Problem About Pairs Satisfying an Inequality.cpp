#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a;
        vector<int> b;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            if(x < i+1){
                a.push_back({x,i+1});
                b.push_back(x);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int m = a.size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            int v = a[i].second;
            int up = upper_bound(b.begin(),b.end(),v)-b.begin();
            if(m - up > 0){
                cnt += m-up;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}