#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
signed main(){
    int n; cin>>n;
    char a[n][n];
    for(int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int dp[n][n];
    memset(dp,0,sizeof dp);
    if(a[n-1][n-1] != '*')dp[n-1][n-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1 && j==n-1)continue;
            if(a[i][j] != '*'){
                int v1=0,v2=0;
                if(i+1<n && a[i+1][j]!='*'){
                    v1=dp[i+1][j];
                }
                if(j+1<n && a[i][j+1]!='*'){
                    v2=dp[i][j+1];
                }
                dp[i][j] = (v1%mod+v2%mod)%mod;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][0]<<endl;
    return 0;
}