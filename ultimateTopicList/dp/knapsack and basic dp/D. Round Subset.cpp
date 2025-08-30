#include<bits/stdc++.h>
using namespace std;
#define int long long

void calc(vector<int> &a,vector<int> &t,vector<int> &f,int n){
    for(int i = 0; i < n; i++){
        int v = a[i];
        while(v>0 && v % 2 == 0){
            t[i]++;
            v/=2;
        }
        while(v>0 && v % 5 == 0){
            f[i]++;
            v/=5;
        }
    }
    return;
}

signed main(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    vector<int> t(n);
    vector<int> f(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    calc(a,t,f,n);
    int p5 = 0;
    for(auto x: f){
        p5+=x;
    }
    int dp[2][k+1][p5+1];
    memset(dp, -1, sizeof dp);
    dp[0][0][0]=0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int l = 0; l <= p5; l++){
                int curr = (i&1);
                int next = !curr;

                if(dp[curr][j][l]==-1)continue;

                if(j+1 <= k && l+f[i] <= p5 ){
                    dp[next][j+1][l+f[i]]=max(dp[next][j+1][l+f[i]], dp[curr][j][l]+t[i]);
                }
                dp[next][j][l]=max(dp[next][j][l],dp[curr][j][l]);
            }
        }
    }
    int ans =INT_MIN;
    for(int i = 0; i <= p5; i++){
        ans = max(ans, min(dp[n&1][k][i], i));
    }

    cout<<ans<<endl;
    return 0;
}