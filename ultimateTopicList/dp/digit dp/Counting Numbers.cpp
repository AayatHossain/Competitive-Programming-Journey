#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][11][2][2];
string l,r;

int f(int n, int p,int z, int t, string s){
    if(n == 0)return 1;
    if(p != -1 && dp[n][p+1][z][t]!=-1)return dp[n][p+1][z][t];
    int ub=9;
    if(t){
        ub = s[s.size() - n] - '0';
    }
    int ans = 0;
    for(int i = 0 ;i <= ub; i++){
        if(i==p && !z)continue;
        
        ans+=f(n-1, i, z&(i==0) ,t&(i==ub),s);
    }
    return dp[n][p+1][z][t] = ans;
}

signed main(){
    memset(dp, -1, sizeof dp);

    int n1,n2; cin>>n1>>n2;
    l = to_string(n1-1);
    r = to_string(n2);

    int right = f(r.size(),-1,1,1,r);
    int left = f(l.size(),-1,1,1,l);
    
    cout<<right - left<<endl;


    return 0;
}