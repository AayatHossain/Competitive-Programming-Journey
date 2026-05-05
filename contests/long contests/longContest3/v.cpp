#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
void bfs(vector<vector<char>> &g, vector<vector<bool>> &vis, int si, int sj, int n, int m){
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i < s; i++){
            auto x = q.front();
            q.pop();
            for(auto move: dir){
                int nx = x.first + move.first;
                int ny = x.second + move.second;
                int valid = nx >= 0 && nx < n && ny >= 0 && ny< m && vis[nx][ny] ==false && g[nx][ny] != '#';
                if(valid){
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
}
signed main(){
    int n,m;cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> v(n, vector<bool>(m,false));
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cin>>g[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!v[i][j] && g[i][j]=='.'){
                // cout<<i<<" "<<j<<endl;
                count++;
                bfs(g,v,i,j,n,m);
            }
        }
    }
    cout<<count<<endl;

    return 0;
}