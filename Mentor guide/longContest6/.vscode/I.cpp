#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
// int a[N];
// int dp[N][N];

vector<int> a(N);
vector<int> dp(N,-1);

int f(int curr, int n){
    if(curr==n-1){
        return 0;
    }
    if(curr >= n){
        return LLONG_MAX/2;
    }
    if(dp[curr] != -1)return dp[curr];
    int cost =  LLONG_MAX;
    int v1 = LLONG_MAX;
    int v2 = LLONG_MAX;
    if(curr + 1 < n){
        v1 = abs(a[curr+1] - a[curr]) + f(curr+1, n);
    }
    if(curr+2 < n){
        v2 = abs(a[curr+2] - a[curr]) + f(curr+2, n);
    }
    return dp[curr] = min(v1,v2);
    
}
signed main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    int total = f(0,n);
    cout<<total<<endl;
    return 0;
}