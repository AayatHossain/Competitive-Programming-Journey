#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 501;
const int M = 501;
char g[N][M];
vector<vector<bool>> v(N, vector<bool>(M,false)); 
int k;
vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs2(int i,int j, int t){
    queue<pair<int,int>> q;
    v[i][j]=true;
    q.push({i,j});
    int c = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        c++;
        int ux = p.first;
        int uy = p.second;
        g[ux][uy]='C';
        if(c==t){
            return;
        }
        int x = p.first;
        int y = p.second;
        for(auto m0: moves){
            int nx = x + m0.first;
            int ny = y + m0.second;
            int valid = nx >=1 && nx <= n && ny>=1 && ny<=m && g[nx][ny]=='.';
            if(valid && !v[nx][ny]){
                v[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    return;
}

signed main(){
    cin>>n>>m>>k;
    int x=-1,y=-1;
    int c=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='#'){
                c++;
            }
            if(x==-1 && g[i][j]=='.'){
                x=i;y=j;
            }
        }
    }
    
    int s = (n*m)-c;

    bfs2(x,y,s-k);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='.'){
                g[i][j]='X';
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='C'){
                g[i][j]='.';
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }

    return 0;
}