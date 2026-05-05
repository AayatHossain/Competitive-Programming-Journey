#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1000+1;
const int M = 1000+1;
char g[N][M];
int v[N][N];
pair<int,int> p[N][N];
string path; 
vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

bool bfs(int sx, int sy, int dx, int dy){
    queue<pair<int,int>> q;
    v[sx][sy]=1;
    q.push({sx,sy});
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        int ux = u.first;
        int uy = u.second;
        if(ux==dx && uy==dy){
            return true;
        }
        for(auto mo: moves){
            int vx = ux + mo.first; 
            int vy = uy + mo.second;
            int valid = vx >=1 && vx<=n && vy>=1 && vy<=m && g[vx][vy]!='#' && !v[vx][vy];
            if(valid){
                v[vx][vy]=true;
                q.push({vx,vy});
                p[vx][vy]= {ux,uy};
            } 
        }
    }
    return false;
}

char f(int x,int y, int cx,int cy){
    if(cx==x && cy==y+1){
        return 'R';
    }
    if(cx==x && cy==y-1){
        return 'L';
    }
    if(cy==y && cx == x-1){
        return 'U';
    }
    if(cy==y && cx == x+1){
        return 'D';
    }
    return 'X';
}

void makePath(int sx, int sy, int dx, int dy){
    int cx = dx; int cy = dy;
    
    while(g[cx][cy]!='A'){
        int x = p[cx][cy].first;
        int y = p[cx][cy].second;
        // cout<<x<<" "<<y<<endl;
        path += f(x,y,cx,cy);
        cx = x; cy = y;
        
        
    }
    reverse(path.begin(),path.end());
}

signed main(){
    cin>>n>>m;
    int sx,sy,dx,dy;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                sx=i; sy=j;
            }
            if(g[i][j]=='B'){
                dx=i; dy=j;
            }
        }
    }
    bool ok = bfs(sx,sy,dx,dy);
    if(ok){
        
        // cout<<p[3][7].first<<" "<<p[3][7].second<<endl;
        makePath(sx,sy,dx,dy);
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        cout<<path<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}