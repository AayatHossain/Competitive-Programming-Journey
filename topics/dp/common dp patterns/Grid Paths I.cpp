#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    int n; cin>>n;
    char a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            cin>>a[i][j];
        }
    }
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    if(a[n-1][n-1] != '*')dp[n-1][n-1]=1;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(a[i][j]=='*' || (j==n-1 && i==n-1 ))continue;

            int right=0,bottom=0;
            if(i+1 < n){
                bottom = dp[i+1][j]%mod;
            }
            if(j+1 < n){
                right = dp[i][j+1]%mod;
            }
            dp[i][j] = (right + bottom)%mod;
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}