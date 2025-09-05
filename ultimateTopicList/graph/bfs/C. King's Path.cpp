#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
set<pair<int,int>> m;
const int N = 1e9;
set<pair<int,int>> vis;

bool exists(pair<int,int> p){
   
    if((m.find(p) != m.end())){
        return true;
    }else{
        return false;
    }
}
bool isvisited(pair<int,int> p){
    if(vis.find(p)!=vis.end()){
        return true;
    }else{
        return false;
    }
}

int bfs(int sr,int sc, int er, int ec){
    queue<pair<pair<int,int>,int>> q;
    q.push({{sr,sc},0});
    vis.insert({sr,sc});
    int count = 0;
    while(!q.empty()){
        pair<pair<int,int>,int> p = q.front();
        
        pair<int,int> u = p.first;
        count = p.second;
        
        q.pop();
        if(u.first==er && u.second==ec)return count;
        // cout<<u.first<<" "<<u.second<<" "<<count<<endl;
        for(auto v : moves){
            int nx = v.first+u.first;
            int ny = v.second+u.second;
            int valid = nx>=1 && nx <= N && ny >= 1 && ny <= N && exists({nx,ny}) && !isvisited({nx,ny});
            if(valid){
                q.push({{nx,ny},count+1});
                vis.insert({nx,ny});
            }
        }
    }
    return -1;

}
signed main(){
    int sr,sc,er,ec; cin>>sr>>sc>>er>>ec;
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int u, l,r; cin>>u>>l>>r;
        for(int j = l; j <= r; j++){
            m.insert({u,j});
        }
    }
    // for(auto x: m){
    //     cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    // }
    int c = bfs(sr,sc,er,ec);
    cout<<c<<endl;
    return 0;
}