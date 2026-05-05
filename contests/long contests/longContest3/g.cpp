#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(vector<vector<char>> &g, vector<vector<bool>> &vis, char src, char dst, int i, int j){
    // cout<<src<<" "<<dst<<endl;
    
    int n = g.size();
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = true;
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            auto u = q.front();
            q.pop();
            int ux = u.first;
            int uy = u.second;
            if(g[ux][uy]==dst){
                return count;
            }
            for(auto v: moves){
                int nx = ux + v.first; 
                int ny = uy + v.second;
                int valid = nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] != '#' && g[nx][ny] < dst+1 && !vis[nx][ny];
                if(valid){
                    
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
        count++;
    }
    return -1;
}


signed main()
{
    int t;
    cin >> t;
    int it = 1;
    while (t--)
    {

        string l;
        getline(cin, l);

        int n;
        cin >> n;
        if(n==0){
            cout<<"Case "<<it<<": "<<"Impossible"<<endl;
            it++;
            continue;
        }
        vector<vector<char>> g(n, vector<char>(n));
        vector<int> x(26);
        vector<int> y(26);
        char src = 'A';
        char dst = 'A';
        int sI, sJ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> g[i][j];
                int ch = g[i][j];
                if(ch >=65 && ch<= 90 ){
                    x[ch-'A'] = i; 
                    y[ch-'A'] = j; 
                    dst = max((int)dst, ch);
                }
            }
        }
        // cout<<dst<<endl;
        // for(int i = 0; i < 26; i++){
        //     cout<<char (i+'A')<<" "<<x[i]<<","<<y[i]<<endl;
        // }
        char c = 'A';
        int total = 0;
        while(c < dst){
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            int moves = bfs(g, vis, c, c+1, x[c-'A'], y[c-'A']);
            // cout<<moves<<endl;
            if(moves ==-1){
                total = -1;
                break;
            }else{
                total += moves;
            }
            c++;
        }
        // cout<<total<<endl;
        if(total==-1){
            cout<<"Case "<<it<<": "<<"Impossible"<<endl;
        }else{
            cout<<"Case "<<it<<": "<<total<<endl;
        }
        it++;
        
    }
    return 0;
}