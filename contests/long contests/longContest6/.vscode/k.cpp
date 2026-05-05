#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
vector<vector<int>> a(N, vector<int>(4));
int dp[N][4];
int f(int pos, int prev, int n){
    if(pos > n){
        return 0;
    }
    if(dp[pos][prev] != -1) return dp[pos][prev];
    if(prev==1){
        int v1 = f(pos+1, 2, n) + a[pos][2];
        int v2 = f(pos+1, 3, n) + a[pos][3];
        return dp[pos][prev] = max(v1,v2);
    }
    if(prev==2){
        int v1 = f(pos+1, 1, n) + a[pos][1];
        int v2 = f(pos+1, 3, n) + a[pos][3];
        return dp[pos][prev] = max(v1,v2);
    }
    if(prev==3){
        int v1 = f(pos+1, 2, n) + a[pos][2];
        int v2 = f(pos+1, 1, n) + a[pos][1];
        return dp[pos][prev] = max(v1,v2);
    }
}
signed main(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        int x,y,z; cin>>x>>y>>z;
        a[i][1] = x; 
        a[i][2] = y; 
        a[i][3] = z; 
    }
    for(int i = 1; i <= n; i++){
        dp[i][1] = -1;
        dp[i][2] = -1;
        dp[i][3] = -1;
    }
    int ans = LLONG_MIN;
    for(int i = 1; i <= 3; i++){
        ans = max(ans, f(1, i, n));
    }
    cout<<ans<<endl;
    return 0;
}