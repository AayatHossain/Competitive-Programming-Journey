#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 1;
vector<int> dp(N, -1);
int f(int n)
{
    if (n==0)return 1;
    if( n < 0)return 0;

    if(dp[n]!=-1)return dp[n];
    
    int cnt = 0;
    for(int i = 1; i<= 6; i++){
        cnt = (cnt + f(n-i))%mod;
    }
    return dp[n]=cnt;
}

signed main()
{
    int n;
    cin >> n;
    int v = f(n);
    cout << v << endl;
    return 0;
}