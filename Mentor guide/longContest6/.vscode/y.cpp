#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+7;
pair<int,int> dp[N];
int f(int cn, int cs){
    if(cs==0)return cn;
    if(cs < 0) return LLONG_MAX/2;
    if(dp[cs].first != -1 && dp[cs].second <= cn)return dp[cs].second;
    
    int v1 = f(cn*10 + 7, cs - 7);
    int v2 = f(cn*10 + 4, cs - 4);
    
    dp[cs].second = min (v1,v2);
    dp[cs].first = cs;
    return dp[cs].second;
}
signed main(){
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    int ans = f(0,n);
    if(ans>=LLONG_MAX/2){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}