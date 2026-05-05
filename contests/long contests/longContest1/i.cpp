#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,k;cin>>n>>k;string s;cin>>s;
    map<char, int> m;
    for(int i = 0; i < n; i++){
        m[s[i]]++;
    }
    int ans;
    if(m.size() < k){
        ans = 0;
    }else{
        int minV = INT_MAX;
        for(auto x: m){
            minV = min(minV, x.second);
        }
        ans = k*minV;
    }
    cout<<ans<<endl;

    return 0;
}