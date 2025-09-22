#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

int dfs(int x,int y,vector<vector<char>> &g, vector<vector<bool>> &vis,int n,int m){
    vis[x][y]=true;
    int c = 1;
    for(auto move: moves){
        int nx = x + move.first;
        int ny = y + move.second;
        int valid = nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && g[nx][ny]=='#';
        if(valid){
             c += dfs(nx,ny,g,vis,n,m);
        }
    }
    return c;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<vector<char>> g(n, vector<char>(m));
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
            }
        }
        int num = 0;
        for(int i =0;i<n;i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && g[i][j]=='#'){
                    int v = dfs(i,j,g,vis,n,m);
                    num+=v*v;
                    // cout<<v<<endl;
                }
            }
        }
        int den = n*m;
        int ge = __gcd(num,den);
        // cout<<num<<" "<<den<<" "<<ge<<endl;
        num/=ge;
        den/=ge;
        if(num==0){
            cout<<0<<endl;
        }else if(den==1){
            cout<<num<<endl;
        }else{
            cout<<num<<" / "<<den<<endl;
        }
        
        
    }
    return 0;
}