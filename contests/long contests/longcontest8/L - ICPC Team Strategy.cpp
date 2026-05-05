#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=12;
int n;
int a[3][N];
int dp[3][1<<N][280+1];
int setbits(int mask){
    int c=0;
    for(int i = 0 ;i < n; i++){
        if((mask&(1<<i))!=0){
            c++;
        }
    }
    return c;
}
int f(int p, int mask, int m){
    // cout<<m<<endl;
    if(m==0 || ((mask==((1<<n)-1))&& (m >= 0)))return setbits(mask);
    if(m<0)return setbits(mask)-1;
    if(dp[p][mask][m]!=-1)return dp[p][mask][m];
    if(p==0){
        int ans1=0, ans2=0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if((mask&(1<<i))==0){
                ans1=f(1,(mask | (1<<i)), m - a[1][i]);
                ans2=f(2,(mask | (1<<i)), m - a[2][i]);
                ans = max(ans,max(ans1,ans2));
            }
        }
        return dp[p][mask][m]=ans;
    }else if(p==1){
        int ans1=0, ans2=0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if((mask&(1<<i))==0){
                ans1=f(0,(mask | (1<<i)), m - a[0][i]);
                ans2=f(2,(mask | (1<<i)), m - a[2][i]);
                ans = max(ans,max(ans1,ans2));
            }
        }
        return dp[p][mask][m]=ans;
    }else{
        int ans1=0, ans2=0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if((mask&(1<<i))==0){
                ans1=f(0,(mask | (1<<i)), m - a[0][i]);
                ans2=f(1,(mask | (1<<i)), m - a[1][i]);
                ans = max(ans,max(ans1,ans2));
            }
        }
        return dp[p][mask][m]=ans;
    }
}
signed main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++){
                cin>>a[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        int ans = max(f(0,0,280),max(f(1,0,280),f(2,0,280)));
        cout<<ans<<endl;
    }
}