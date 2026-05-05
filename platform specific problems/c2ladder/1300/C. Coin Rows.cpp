#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> a(2, vector<int>(n) );
        for(int i = 0; i < n;  i++){
            cin>>a[0][i];
        }
        for(int i = 0; i < n;  i++){
            cin>>a[1][i];
        }
        vector<vector<int>> p(2, vector<int>(n) );
        p[0][0]=a[0][0];
        p[1][0]=a[1][0];
        for(int i = 1; i < n; i++){
            p[0][i]=p[0][i-1]+a[0][i];
            p[1][i]=p[1][i-1]+a[1][i];
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int v1 = p[0][n-1]-p[0][i];
            int v2 = p[1][i]-a[1][i];
            ans = min(ans, max(v1,v2));
        }
        cout<<ans<<endl;
    }
    return 0;
}