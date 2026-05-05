#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 16;
vector<vector<int>> dp(N, vector<int>(1<<N));
vector<vector<int>> a(N, vector<int>(N));
int n;

int f(int i, int mask){
    if(i==n || (mask==(1<<n)-1))return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    
    dp[i][mask]=INT_MIN;
    for(int j = 0; j < n; j++){
        if((mask & (1<<j))==0 ){
            dp[i][mask]=max(dp[i][mask], a[i][j] + f(i+1, (mask | (1<<j))));
        }
    }
    return dp[i][mask];
}

signed main(){
    int t; cin>>t;
    int c = 1;
    while(t--){
        cin>>n;
        for(int i=0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>a[i][j];
            }
        }
        for(int i=0; i < n; i++){
            for(int j = 0; j < (1<<n); j++){
                dp[i][j]=-1;
            }
        }
        cout<<"Case "<<c<<": "<<f(0,0)<<endl;
        c++;
        
    }
    return 0;
}