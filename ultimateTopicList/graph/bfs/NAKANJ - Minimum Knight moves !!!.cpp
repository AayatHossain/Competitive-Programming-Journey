#include<bits/stdc++.h>
using namespace std;
int v[8][8];
int n = 8;

vector<pair<int,int>> moves = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

struct node{
    int i,j,w;
};
int bfs(int si,int sj,int di, int dj){
    queue<node> q;
    v[si][sj]=1;
    q.push({si,sj,0});
    
    while(!q.empty()){
        node p = q.front();
        q.pop();
        int x=p.i;
        int y=p.j;
        int W = p.w;
        if(x==di && y==dj)return W;
        for(auto m: moves){
            int nx = x+m.first;
            int ny = y+m.second;
            int ok = nx >=0 && nx<n && ny>=0 && ny<n && !v[nx][ny];
            if(ok){
                q.push({nx,ny,W+1});
                v[nx][ny]=1;
            }
        }
    }
    return -1;

}

signed main(){
    int t; cin>>t;
    while(t--){
        memset(v,0,sizeof v);

        string s1,s2; cin>>s1>>s2;
        int si = abs('a' - s1[0]);
        int sj = abs('1' - s1[1]);
        int di = abs('a' - s2[0]);
        int dj = abs('1' - s2[1]);
        // cout<<si<<" "<<sj<<" "<<di<<" "<<dj<<endl;
        int r =  bfs(si,sj,di,dj);
        cout<<r<<endl;
    }
    return 0;
}