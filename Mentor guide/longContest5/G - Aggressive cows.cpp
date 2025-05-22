#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ok(vector<int> &a, int c, int k){
    int cows = 1;
    int curr = a[0];
    for(int i = 1; i < a.size(); i++){
        if(a[i] - curr >= k){
            cows++; curr = a[i];
        }
    }
    return cows >= c;
}
signed main(){
    int t; cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int l = 0, r = 1e9+7;
        int m;
        while(r > l+1){
            m = l + (r-l)/2;
            if(ok(a,c,m)){
                l = m;
            }else{
                r = m;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}