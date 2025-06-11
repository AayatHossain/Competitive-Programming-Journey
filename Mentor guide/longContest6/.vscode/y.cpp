#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+7;
int n;
int dp[N][N];
int f(int sum, int num){
    if(sum==n)return num;
    if(sum > n) return LLONG_MAX/2;
    if(dp[sum][num] != -1)return dp[sum][num];
    int v1 = f(sum + 4, num*10 + 4);
    int v2 = f(sum + 7, num*10 + 7);
    return dp[sum][num] = min(v1,v2);
}
signed main(){
    memset(dp, -1, sizeof dp);
    cin>>n;
    int ans = f(0,0);
    if(ans==LLONG_MAX/2){
        cout<<-1<<endl;
    }else{
    cout<<f(0,0)<<endl;

    }
}