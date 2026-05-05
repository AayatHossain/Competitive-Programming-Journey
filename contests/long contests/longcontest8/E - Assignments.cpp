#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int dp[N][1<<N];
int n;
int a[N][N];
int f(int i, int m){
    if(i==n)return 1;
    if(dp[i][m]!=-1)return dp[i][m];
    int ans=0;
    for(int j = 0; j < n; j++){
      
        
        if(a[i][j]==1 && ((m&(1<<j))==0)){
            ans+=f(i+1, (m|(1<<j)));
            
        }
    }
   
    return dp[i][m]=ans;
}
signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j =0; j <n; j++){
                cin>>a[i][j];
                // cout<<a[i][j]<<" ";
            }
        }
        
        memset(dp, -1, sizeof dp);
        cout<<f(0,0)<<endl;
    }
    return 0;
}