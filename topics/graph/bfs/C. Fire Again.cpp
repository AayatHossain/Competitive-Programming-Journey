#include<bits/stdc++.h>
using namespace std;
const int N = 2001;
int n,m;
int k;
vector<vector<bool>> vis(N, vector<bool>(N,false));
vector<vector<int>> g(N, vector<int>(N,-1));

vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

struct node{
    int i,j,c;
};
queue<node> q;
signed main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    cin>>k;
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        q.push({x,y,0});
        g[x][y]=0;
        vis[x][y]=true;
    }

    node res = {-1,-1,-1};
    while(!q.empty()){
        int x = q.front().i;
        int y = q.front().j;
        int d = q.front().c;

        q.pop();

        for(auto move: moves){
            int nx = x + move.first;
            int ny = y + move.second;

            int valid = nx >=1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny];

            if(valid){
                g[nx][ny] = g[x][y]+1;
                if(g[nx][ny] > res.c){
                    res.i=nx;
                    res.j=ny;
                    res.c=g[nx][ny];
                }
                vis[nx][ny]=true;
                q.push({nx,ny,g[nx][ny]});
            }
        }
    }
    if(k==n*m){
        res.i = 1;
        res.j = 1;
    }
    cout<<res.i<<" "<<res.j<<endl;
}
