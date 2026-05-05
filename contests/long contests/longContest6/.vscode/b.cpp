#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxx = 101+101;
int a[mxx][mxx];
int dp[mxx][mxx];
int n,mx;
int f(int i, int j){
    if(i==mx-1 && j == n-1){
        return a[i][j];
    }
    int valid = i >= 0 && i < mx && j >= 0 && j < mx && a[i][j] != -1;
    if(!valid){
        return LLONG_MIN/2;
    }
    if(dp[i][j] != -1)return dp[i][j];
    int v1 = f(i+1,j+1) + a[i][j];
    int v2 = f(i+1,j-1) + a[i][j];
    return dp[i][j] = max(v1,v2);
}
signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        cin>>n;
        mx = n+(n-1);
        memset(a, -1, sizeof a);
        memset(dp, -1, sizeof dp);
     
        for(int i = 0; i < n; i++){
            int index = abs(n-i-1);
            for(int j = 0; j <= i; j++){
                int x; cin>>x;
                // cout<<x<<endl;
                a[i][index] = x;
                index += 2;
            }
        }

        for(int i = 0; i < n-1; i++){
            int index = i+1;
            for(int j = 0; j <= n-i-2; j++){
                int x; cin>>x;
                // cout<<x<<endl;
                a[n+i][index] = x;
                index += 2;
            }
        }


        // for(int i = 0; i < mx; i++){
        //     for(int j = 0; j < mx; j++){
        //         cout<<a[i][j]<<"      ";
        //     }
        //     cout<<endl;
        // }
        cout<<"Case "<<c<<": "<<f(0,n-1)<<endl;
        c++;
        
    }
}