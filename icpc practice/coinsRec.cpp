#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int X = 1e6 + 1;
const int N = 100+1;
vector<int> dp(X, -1);
vector<int> a(N);
int n,x;
int f(int m)
{
    if (m==0)return 1;
    if( m < 0)return 0;

    if(dp[m]!=-1)return dp[m];
    
    int cnt = 0;
    for(int i = 0; i< n; i++){
        cnt = (cnt + f(m-a[i]))%mod;
    }
    return dp[m]=cnt;
}

signed main()
{
   cin>>n>>x;
    for(int i = 0; i < n;i++){
        cin>>a[i];
    }
    cout<<f(x)<<endl;
    return 0;
}