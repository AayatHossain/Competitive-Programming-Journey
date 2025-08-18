#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3;
vector<int> a(N);
int dp[N][N*N+1];
int n;

int f(int i, int l,int s){
    if(i==n){
        int v = max(l, (int)ceil(s/2));
        return v;
    }
    if(dp[i][s]!=-1)return dp[i][s];
    int large=a[i];
    if(l > large)large = l;
    return dp[i][s]=f(i+1,large,s+a[i])+f(i+1,l,s);
}
signed main(){
    cin>>n;
    for(int i = 0; i < n; i++)cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<f(0, INT_MIN, 0)<<endl;
}