#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> vis(9, vector<bool>(9,false));
vector<int> dx = {1,1,-1,-1,2,2,-2,-2};
vector<int> dy = {2,-2,2,-2,1,-1,1,-1};

struct node{
    int u,v,c;
};

int bfs(int si,int sj,int di, int dj){
    queue<node> q;
    vis[si][sj]=true;
    q.push({si,sj,0});
    while(!q.empty()){
        node n = q.front();
        q.pop();
        int ux = n.u;
        int uy = n.v;
        int uc = n.c;
        if(ux==di && uy==dj){
            return uc;
        }
        for(int i = 0; i < 8; i++){
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            bool valid = nx >= 1 && nx<=8 && ny>=1 && ny<=8 && !vis[nx][ny];
            if(valid){
                vis[nx][ny]=true;
                q.push({nx,ny,uc+1});
            }
        }
    }
    
}

signed main(){
    int t; cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int si = s1[0] - 'a' + 1;
        int sj = s1[1] - '0' ;

        int di = s2[0] - 'a' + 1;
        int dj = s2[1] - '0' ;

        // cout<<si<<" "<<sj<<endl;
        // cout<<di<<" "<<dj<<endl;

        for(int i = 1; i <= 8; i++){
            vis[i] = vector<bool>(9,false);
        }

        int x = bfs(si,sj,di,dj);
        cout<<x<<'\n';
    }   
    return 0;
}