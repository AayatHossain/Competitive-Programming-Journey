#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<char>> a(3, vector<char>(n+1));
        vector<int> dp(n+1,0);
        for(int i = 1; i <= n; i++){
            cin>>a[1][i];
        }
        for(int i = 1; i <= n; i++){
            cin>>a[2][i];
        }

        dp[0]=0;
        if(a[1][1]!=a[2][1])dp[1]=1;

        for(int i = 2; i <= n; i++){
            int cost = (a[1][i] != a[2][i]);
            int v1 = dp[i-1] + cost;
            
            int cost2 = (a[1][i-1] != a[1][i]) + (a[2][i-1] != a[2][i]);
            int v2 = dp[i-2] + cost2;

            dp[i] = min(v1,v2);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}