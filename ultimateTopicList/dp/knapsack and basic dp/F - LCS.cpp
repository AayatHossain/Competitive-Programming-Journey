#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, m;
string s, t;
signed main()
{
    cin >> s >> t;
    n = s.size();
    m = t.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof dp);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // cout<<dp[n][m]<<endl;
    string a;
    int i=n,j=m;
    while(i > 0 && j > 0){
        if(s[i-1]==t[j-1]){
            a+=s[i-1];
            i--;j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(a.begin(),a.end());
    cout << a << endl;
}