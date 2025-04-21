#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
int bfs(vector<vector<char>> &a, int i, int j, int n, int m){
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    int moves = 0;
    q.push({i,j});
    vis[i][j] = true;
    while(!q.empty()){
        int s = q.size();
        for(int k = 0; k < s; k++){
            auto u = q.front();
            q.pop();
            int ux = u.first;
            int uy = u.second;
            if(a[ux][uy]=='h'){
                return moves;
            }
            for(auto x: dir){
                int vx = ux + x.first;
                int vy = uy + x.second;
                int valid = vx < n && vx >= 0 && vy < m && vy >= 0 && a[vx][vy] != '#' && a[vx][vy] != 'm' && !vis[vx][vy];
                if(valid){
                    q.push({vx,vy});
                    vis[vx][vy] = true;
                }
            }
        }
        moves++;
    }
    return moves;

}
int main(){
    int t;cin>>t;
    int it = 1;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<char>> a(n, vector<char>(m));
        vector<pair<int,int>>pos;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>a[i][j];
                if(a[i][j]=='a' || a[i][j] =='b' || a[i][j]=='c'){
                    pos.push_back({i,j});
                }
            }
        }
        int count = 0;
        for(auto x: pos){
            int moves = bfs(a,x.first,x.second,n,m);
            count = max(count, moves);
        }
        cout<<"Case "<<it<<": "<<count<<endl;
        it++;

    }
}