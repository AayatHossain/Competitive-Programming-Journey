#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N = 1e5+1;
vector<int> a(N);
vector<int> b(N);
int dp[3][N];
int f(int prev, int i){
    if(i==n)return 0;
    if(dp[prev][i] != -1 )return dp[prev][i];
    if(prev==1){
        int v1 = b[i] + f(2, i+1);
        int v2 = f(1, i+1);
        return dp[prev][i]= max(v1,v2);
    }else{
        int v1 = a[i] + f(1, i+1);
        int v2 = f(2, i+1);
        return dp[prev][i]= max(v1,v2);
    }
}
signed main(){
    cin>>n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    cout<<max(f(1, 0), f(2,0))<<endl;
   
    return 0;
}