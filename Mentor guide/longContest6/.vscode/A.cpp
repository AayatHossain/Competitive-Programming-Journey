#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
vector<vector<int>> a(N, vector<int>(3));
vector<vector<int>> dp(N, vector<int>(3, -1));

int f(int pos, int prev, int n){
    if(pos==n){
        return 0;
    }
    if(dp[pos][prev] != -1){
        return dp[pos][prev];
    }
    if(prev==0){
        int v1 = f(pos+1, 1,n) + a[pos][1];
        int v2 = f(pos+1, 2,n) + a[pos][2];
        return dp[pos][prev] = min(v1,v2);
    }else if(prev==1){
        int v1 = f(pos+1, 0,n) + a[pos][0];
        int v2 = f(pos+1, 2,n) + a[pos][2];
        return dp[pos][prev] = min(v1,v2);
    }else{
        int v1 = f(pos+1, 1,n) + a[pos][1];
        int v2 = f(pos+1, 0,n) + a[pos][0];
        return dp[pos][prev] = min(v1,v2);
    }
}

signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        string s;
        getline(cin, s);
        int n; cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i][0];
            cin>>a[i][1];
            cin>>a[i][2];
        }
        int ans = LLONG_MAX;
        for(int i = 0; i < 3; i++){
            ans = min(ans, f(0,i, n));
        }
        cout<<"Case "<<c<<": "<<ans<<endl;
        c++;

        for(int i = 0; i < N; i++){
            a[i].clear();
            dp[i][0] = -1;
            dp[i][1] = -1;
            dp[i][2] = -1;
        }

    }
    return 0;
}