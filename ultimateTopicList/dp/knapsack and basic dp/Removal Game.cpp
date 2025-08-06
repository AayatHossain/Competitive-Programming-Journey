#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++){
        dp[i][i]= a[i];
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            if(i+1==j){
                dp[i][j]=max(a[i],a[j]);
            }else{
                int v1 = a[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int v2 = a[j] + min(dp[i][j-2], dp[i+1][j-1]);
                dp[i][j] = max(v1,v2);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}