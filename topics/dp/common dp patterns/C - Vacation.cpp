#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j ++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dp(2, vector<int>(3,0));
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];
    for(int i = 1; i < n; i++){
        int curr = (i&1);
        int prev = !curr;
        for(int j = 0; j < 3; j++){
            int mx = INT_MIN;
            for(int k = 0; k < 3; k++){
                if(k!=j){
                    mx = max(mx, dp[prev][k] + a[i][j]);
                }
            }
            dp[curr][j]=mx;
        }
    }
    cout<<max(dp[!(n&1)][0],max(dp[!(n&1)][2], dp[!(n&1)][1]))<<'\n';
    return 0;
}