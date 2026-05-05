#include<bits/stdc++.h>
using namespace std;
const int N = 251;
char g[N][N];
bool vis[N][N];
int n,m;
int k=0,v=0;
int ks=0,vs=0;

vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int i, int j){
    if(g[i][j]=='k')k++;
    if(g[i][j]=='v')v++;
    vis[i][j]=true;
    for(auto move: moves){
        int nx = i+move.first;
        int ny = j+move.second;
        int valid = nx>=1 &&  nx<=n && ny>=1 && ny<=m && !vis[nx][ny] && g[nx][ny]!='#';
        if(valid){
            dfs(nx,ny);
        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        for(int j = 1; j<=m; j++){
            cin>>g[i][j];
            vis[i][j]=false;
        }
    } 

    for(int i =1;i<=n;i++){
        for(int j = 1; j<=m; j++){
            if(!vis[i][j] && g[i][j]!='#'){
                k=0;v=0;
                dfs(i,j);
                if(k>v){    
                    ks+=k;
                }else{
                    vs+=v;
                }
            }
        }
    }
    cout<<ks<<" "<<vs;

    return 0;
}