#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i==0){
            p[0]=a[0];
        }else{
            p[i]=p[i-1]+a[i];
        }
    }
    int dp[n][n];
    memset(dp, 0, sizeof dp);
   
    for(int i =n-2; i >= 0; i--){
        for(int j = i+1; j < n; j++){
           dp[i][j]=LLONG_MAX;
            for(int k = i; k < j; k++){
                int sum;
                if(i-1 >=0){
                    sum = p[j]-p[i-1];
                }else{
                    sum = p[j];
                }
                dp[i][j]= min(dp[i][k] + dp[k+1][j] + sum, dp[i][j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}