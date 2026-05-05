#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
void bfs(vector<vector<char>> &g, vector<vector<bool>> &vis,vector<vector<char>> path, string &ans, int si, int sj, int n, int m){
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int found = 0;
    int di = -1, dj = -1;
    while(!q.empty() && found==0){
        int s = q.size();
        for(int i = 0; i < s; i++){
            auto x = q.front();
            q.pop();
            if(g[x.first][x.second]=='B'){
                found = 1;
                di = x.first;
                dj = x.second;
                break;
            }
            for(int i = 0; i < 4; i++){
                auto move = dir[i];
                int nx = x.first + move.first;
                int ny = x.second + move.second;
                int valid = nx >= 0 && nx < n && ny >= 0 && ny< m && vis[nx][ny] ==false && g[nx][ny] != '#';
                if(valid){
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                    if(i==0){
                        path[nx][ny] = 'R';
                    }else if(i==1){
                        path[nx][ny] = 'L';
                    }else if(i==2){
                        path[nx][ny] = 'D';
                    }else{
                        path[nx][ny] = 'U';

                    }
                }
            }
        }
    }
    if(found){
        while(g[di][dj] != 'A'){
            if(path[di][dj]=='U'){
                di++; ans+='U';
            }else if(path[di][dj]=='D'){
                di--; ans+='D';
            }else if(path[di][dj]=='R'){
                dj--; ans+='R';
            }else{
                dj++;ans+='L';
            }
        }
        reverse(ans.begin(),ans.end());
    }
}
signed main(){
    int n,m;cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> v(n, vector<bool>(m,false));
    vector<vector<char>> path(n, vector<char>(m));
    int si = -1, sj = -1;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                si = i;
                sj = j;
            }
        }
    }
    string ans;
    bfs(g,v,path,ans,si, sj, n,m);
    if(ans.size()==0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }

    return 0;
}