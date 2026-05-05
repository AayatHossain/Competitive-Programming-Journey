#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, m,x,y;
string s;
vector<pair<int,int>> mons;
char g[N][N];
int d[N][N];
int dA[N][N];
bool v[N][N];

char par[N][N];
vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
vector<char> dir = {'R','L','D','U'};

void bfs(){
    queue<pair<int,int>> q;
    for(auto mon: mons){
        q.push({mon.first, mon.second});
        v[mon.first][mon.second]=true;
        d[mon.first][mon.second]=0;
    }
    while(!q.empty()){
        int ox = q.front().first;
        int oy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++ ){
            pair<int,int> move = moves[i];
            int nx = ox + move.first;
            int ny = oy + move.second;
            int valid = nx >=1 && nx <= n && ny>=1 && ny <=m && !v[nx][ny] && g[nx][ny]!='#';
            if(valid){
                v[nx][ny] = true;
                d[nx][ny] = 1 + d[ox][oy];
                q.push({nx,ny});
               
            }
        }
    }
}
pair<int,int> bfs1(int k, int l){
    queue<pair<int,int>> q;
    q.push({k,l});
    v[k][l]=true;
    dA[k][l]=0;
    while(!q.empty()){
        int ox = q.front().first;
        int oy = q.front().second;
        q.pop();
        if(ox==n || ox == 1 || oy==1 || oy==m){
            return {ox,oy};
        }
        // cout<<ox<<" "<<oy<<endl;
        for(int i = 0; i < 4; i++){
            pair<int,int> move = moves[i];
            int nx = ox + move.first;
            int ny = oy + move.second;
            int valid = nx >=1 && nx <= n && ny>=1 && ny <=m && !v[nx][ny] && (g[nx][ny]!='#');
            if(valid && (d[nx][ny] == -1 || dA[ox][oy] + 1 < d[nx][ny])){
                v[nx][ny] = true;
                dA[nx][ny] = 1 + dA[ox][oy];
                q.push({nx,ny});
                par[nx][ny] = dir[i];

            }
        }
    }
    return {-1,-1};
}

void makePath(int fx, int fy){
    par[x][y] = 'X';
    int cx = fx, cy = fy;
    while(par[cx][cy]!='X'){
        char direction = par[cx][cy];
        s += direction;
        if(direction=='L'){
            cy++;
        }else if(direction=='R'){
            cy--;
        }else if(direction=='U'){
            cx++;
        }else{
            cx--;
        }
    }
    reverse(s.begin(),s.end());
}

signed main(){
    cin>>n>>m;
    
    for(int i = 1; i <=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='M'){
                mons.push_back({i,j});
            }
            if(g[i][j]=='A'){
                x = i; y = j;
            }
        }
    }

    memset(v, false, sizeof v);
    for(int i = 1; i<= n;i++){
        for(int j = 1; j<=m;j++){
           d[i][j]=-1;
        }
    }
    bfs();
    
    memset(v, false, sizeof v);
    for(int i=1; i<=n;i++){
        for(int j=1;j<=m;j++){
            dA[i][j]=-1;
        }
    }
    pair<int,int> f = bfs1(x,y);
    if(f.first != -1){
        // cout<<f.first<<" "<<f.second<<endl;
        makePath(f.first,f.second);
        cout<<"YES"<<endl;
        cout<<s.size()<<endl;
        cout<<s<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}