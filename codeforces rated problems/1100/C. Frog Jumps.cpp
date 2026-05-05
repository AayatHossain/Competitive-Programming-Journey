#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n=s.size();
        vector<int> a;
        for(int i = 0; i < n; i++){
            if(s[i]=='R'){
                a.push_back(i+1);
            }
        }
        int m = a.size();
        int ans = INT_MIN;
        for(int i = 1; i < m; i++){
            ans = max(ans, a[i]-a[i-1]);
        }
        if(a.size()>=1){
            ans = max(ans, max(a[0], n - a[m-1] + 1));
        }
        if(ans==INT_MIN){
            ans=n+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}