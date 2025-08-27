#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int n, x; cin>>n>>x;
    int dp[n+1][x+1];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i < n; i++  ){
        int x1, x2; cin>>x1>>x2;

        for(int j = 0; j <= x; j++){
            if(dp[i][j]==1){
                
                if(j + x1 <= x){
                    dp[i+1][j+x1]=1;
                }
                if(j + x2 <= x){
                    dp[i+1][j+x2]=1;
                }
            }
        }
    }
    if(dp[n][x] ==1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}