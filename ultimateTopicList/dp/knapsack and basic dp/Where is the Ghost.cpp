#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

signed main(){
    int n; 
    cin >> n;
    vector<int> a(n);
    int v = 2520;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]%=v;
    }
    vector<vector<int>> dp(n, vector<int>(v,0));
    dp[0][a[0]]=1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < v; j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j = 0; j < v; j++){
            
            if(dp[i-1][j] >= 1){
                dp[i][(j+(a[i]%v))%v]++;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < v; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][0]<<endl;
    return 0;
}
