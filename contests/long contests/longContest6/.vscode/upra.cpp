#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 160;
char a[N][N];
int dp[N][N][2];

int f(int w, int i, int j, int face, int n, int m){
    int invalid = i < 0 || i >= n || j < 0 || j >= m;
   
    if(invalid)return LLONG_MAX/2;

    if(a[i][j]=='W'){
  
        w--;
        // cout<<w<<" "<<i<<" "<<j<<endl;
    }
    if(w==0){
        return 0;
    }
    

    int v1 = LLONG_MAX/2, v2 = LLONG_MAX/2;

    if(face==1){
        v1 = f(w,i,j+1,1,n,m)+1;
        v2 = f(w,i+1,j,0,n,m)+1;
    
        return min(v1,v2);
    }else{
        v1 = f(w,i,j-1,0,n,m)+1;
        v2 = f(w,i+1,j,1,n,m)+1;
        return min(v1,v2);
    }
}

signed main(){
    memset(dp, -1, sizeof(dp));
    int n,m;cin>>n>>m;
    int w = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j]=='W'){
                w++;
            }
        }
    }
    // cout<<w<<endl;
    int ans = f(w,0,0,1,n,m);
    cout<<ans<<endl;

}