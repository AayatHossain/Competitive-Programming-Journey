#include<bits/stdc++.h>
using namespace std;
const int N =1001;
int n,m;
char g[N][N];
int v[N][N];

vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

void bfs(int i, int j){
    queue<pair<int,int>> q;
    v[i][j]=1;
    q.push({i,j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto mo: moves){
            int nx = x + mo.first;
            int ny = y + mo.second;
            int valid = nx>=1 && nx <= n && ny>=1 && ny<= m && !v[nx][ny] && g[nx][ny]=='.';
            if(valid){
                v[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}

signed main(){
    memset(v, 0, sizeof v);
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    int r=0;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='.' && !v[i][j]){
                r++;
                bfs(i,j);
            }
        }
    }
    cout<<r<<endl;
    return 0;

}