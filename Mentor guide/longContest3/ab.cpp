#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[1000][1000];
pair<int,int> par[1000][1000];
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
pair<int,int> aStart;
pair<int,int> aEnd;
string ans;
bool aturn = false;
bool possible = false;
queue<pair<int,int>> q;


void bfs(){
    while(!q.empty()){
        pair<int,int> curr = q.front();
        int ux = curr.first;
        int uy = curr.second;
        if(aturn && (ux==0 || ux == n-1 || uy == 0 || uy==m-1)){
            possible = true;
            aEnd = curr;
            return;
        }
        q.pop();
        for(auto x: dir){
            int vx = ux + x.first;
            int vy = uy + x.second;
            int valid = vx < n && vx >= 0 && vy < m && vy >= 0;
            // int valid = 1;
            if(valid){
                int uTime = g[ux][uy];
                int vTime = g[vx][vy];
                if(uTime + 1 < vTime){
                    g[vx][vy] = uTime + 1;
                    q.push({vx, vy});
                    par[vx][vy] = {ux, uy};
                }
            }
        }
    }
}

void makePath(){
    pair<int,int> start = aStart;
    pair<int,int> end = aEnd;
    pair<int,int> temp = aEnd;
    while(temp.first != aStart.first && temp.second != aStart.second){
        int vx = temp.first;
        int vy = temp.second;
        int ux = par[vx][vy].first;
        int uy = par[vx][vy].second;
        if(vx - 1 == ux) ans += 'D';
        if(vx + 1 == ux) ans += 'W';
        if(vy + 1 == uy) ans += 'L';
        if(vy - 1 == uy) ans += 'R';
        temp = {ux, uy}; 
    }
    reverse(ans.begin(), ans.end());
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin>>c;
            if (c == 'M') {g[i][j] = 0; q.push({i,j});}
            else if (c == '#') g[i][j] = 0;
            else if (c == 'A') { aStart.first = i; aStart.second = j; }
            else if (c == '.') g[i][j] = INT_MAX;
        }
    }
    bfs();
    aturn = true;
    g[aStart.first][aStart.second] = 0;
    bfs();
    q.push({aStart.first,aStart.second});
    if(possible){
        makePath();
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}