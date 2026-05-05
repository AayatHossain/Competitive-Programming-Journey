#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> botPos;
vector<pair<int,int>> targetPos;
vector<vector<pair<int,int>>> targetPerm;
vector<pair<int,int>> directions = {{-1,0},{1,0}, {0,1}, {0, -1}};

void makePerm(){
    pair<int,int> a = targetPos[0];
    pair<int,int> b = targetPos[1];
    pair<int,int> c = targetPos[2];

    vector<pair<int,int>> temp(3);
    temp[0] = a;
    temp[1] = b;
    temp[2] = c;
    targetPerm.push_back(temp);
    temp[0] = a;
    temp[1] = c;
    temp[2] = b;
    targetPerm.push_back(temp);
    temp[0] = b;
    temp[1] = a;
    temp[2] = c;
    targetPerm.push_back(temp);
    temp[0] = b;
    temp[1] = c;
    temp[2] = a;
    targetPerm.push_back(temp);
    temp[0] = c;
    temp[1] = a;
    temp[2] = b;
    targetPerm.push_back(temp);
    temp[0] = c;
    temp[1] = b;
    temp[2] = a;
    targetPerm.push_back(temp);

    // for(auto x: targetPerm){
    //     for(auto y: x){
    //         cout<<y.first<<" "<<y.second<<"------";
    //     }
    //     cout<<endl;
    // }
}

int bfs(vector<vector<char>> &g, int n, int si, int sj, int di, int dj){
    vector<vector<bool>> vis(n,vector<bool>(n));
    queue<pair<int,int>> q;
    int moves = 0;
    q.push({si,sj});
    vis[si][sj] = true;
    while(!q.empty()){
        int size = q.size();
        for(int k = 0; k < size; k ++){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(x==di && y == dj){
                return moves;
            }
            for(auto l: directions){
                int nx = x + l.first;
                int ny = y + l.second;
                int valid = nx >= 0 && nx < n && ny >= 0 && ny < n && vis[nx][ny] == false && g[nx][ny] != '#';
                if(valid){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        moves++;
    }
    return -1;

}

signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        int n;cin>>n;
        vector<vector<char>> g(n,vector<char>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c;cin>>c;
                if(c=='A' || c=='B' || c=='C'){
                    botPos.push_back({i,j});
                }else if(c=='X'){
                    targetPos.push_back({i,j});
                }
                g[i][j] = c;
            }
        }
        makePerm();
        int ans = INT_MAX;
        for(auto perm1: targetPerm){
            pair<int,int> aX = perm1[0];
            int aDi = aX.first;
            int aDj = aX.second;
            int ai = botPos[0].first;
            int aj = botPos[0].second;
            int aMoves = bfs(g,n,ai,aj,aDi,aDj);

            pair<int,int> bX = perm1[1];
            int bDi = bX.first;
            int bDj = bX.second;
            int bi = botPos[1].first;
            int bj = botPos[1].second;
            int bMoves = bfs(g,n,bi,bj,bDi,bDj);

            pair<int,int> cX = perm1[2];
            int cDi = cX.first;
            int cDj = cX.second;
            int ci = botPos[2].first;
            int cj = botPos[2].second;
            int cMoves = bfs(g,n,ci,cj,cDi,cDj);
            if(aMoves==-1 || bMoves == -1 || cMoves == -1){
                ans = INT_MAX;
            }else{
                ans = min(ans, max(aMoves, max(bMoves,cMoves)));
            }
        }
        if(ans==INT_MAX){
            cout<<"Case "<<c<<": "<<"trapped"<<endl;
        }else{
            cout<<"Case "<<c<<": "<<ans<<endl;
        }
        c++;
        botPos.clear();
        targetPos.clear();
        targetPerm.clear();
    }
    return 0;
}





// for(auto x: botPos){
//     cout<<x.first<<x.second<<endl;
// }
// cout<<"--"<<endl;
// for(auto x: targetPos){
//     cout<<x.first<<x.second<<endl;
// }
// cout<<"--"<<endl;
// for(int i = 0; i < n; i++){
//     for(int j = 0; j < n; j++){
//         cout<<g[i][j]<<" ";
//     }
//     cout<<endl;
// }