#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    p[0]=a[0];
    for(int i =1; i < n; i++){
        p[i]=p[i-1]+a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j]=0;
        }
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            for(int k = i; k < j; k++){
                int sum;
                if(i-1 >= 0){
                    sum = p[j]-p[i-1];
                }else{
                    sum = p[j];
                }
                dp[i][j]= min(dp[i][k]+dp[k+1][j] + sum, dp[i][j]);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][n-1]<<endl;
    return 0;
}