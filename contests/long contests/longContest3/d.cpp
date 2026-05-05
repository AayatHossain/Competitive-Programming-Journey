#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> kp;
vector<pair<int,int>> knighMoves = {{-2,+1},{-2,-1},{2,1},{2,-1},{-1,2},{1,2},{-1,-2},{1,-2}};
int bfs(vector<vector<char>> &g, int ki, int kj, int di, int dj){
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(g.size(), vector<bool>(g[0].size(), false));
    int m = g.size();
    int n = g[0].size();
    int knighPow = g[ki][kj] - '0';
    int moves = 0;
    q.push({ki,kj});
    vis[ki][kj] = true;
    while(!q.empty()){
        int size = q.size();
        for(int z = 0; z < size; z++){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(x==di && y==dj){
                
                    if(moves % knighPow > 0){
                        return moves/knighPow + 1;
                    }else{
                        return moves/knighPow;
                    }
                
            }
            for(auto k: knighMoves){
                int x1 = k.first;
                int y1 = k.second;
                int nx = x + x1;
                int ny = y + y1;
                int valid = nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny]==false;
                if(valid){
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                } 
                
            }
        }
        moves++;
    }
    return -1;
}

int util(vector<vector<char>> &g, vector<pair<int,int>> &kp, int i, int j){
    int totalMoves = 0;
    for(auto x: kp){
        int ki = x.first;
        int kj = x.second;
        int moves = -1;
        moves = bfs(g,ki,kj,i,j);
    // cout<<moves<<endl;
        if(moves==-1){
            return INT_MAX;
        }

        totalMoves += moves;
    }
    return totalMoves;
}
int main(){
    int c = 1;
    int t;cin>>t;
    while(t--){
        string s;
        getline(cin, s);

        int m, n;cin>>m>>n;
        vector<vector<char>> g(m, vector<char>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char x;
                cin>>x;
                g[i][j]=x;
                if(x != '.'){
                    kp.push_back({i,j});
                }
            }
        }
        // for(auto x: kp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = util(g,kp, i, j);
                ans = min(ans, val);
            }
        }
        kp.clear();
        if(ans==INT_MAX){
            ans = -1;
        }
        cout<<"Case "<<c<<": "<<ans<<'\n';
        c++;
        
    }
    
    return 0;
}