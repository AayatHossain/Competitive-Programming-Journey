#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &m,vector<vector<bool>> &vis, int w, int h, int &count, int i, int j){
    bool valid = (i < h && i >= 0) && (j < w && j >= 0) && (m[i][j] != '#') && (vis[i][j]==false);
    if(valid){
        vis[i][j] = true;
        count++;
        dfs(m,vis,w,h,count,i-1,j);
        dfs(m,vis,w,h,count,i+1,j);
        dfs(m,vis,w,h,count,i,j+1);
        dfs(m,vis,w,h,count,i,j-1);
    }else{
        return;
    }
}
signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        int w,h;cin>>w>>h;
        vector<vector<char>> m(h, vector<char>(w));
        vector<vector<bool>> vis(h, vector<bool>(w, false));
        int sI, sJ;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin>>m[i][j];
                if(m[i][j]=='@'){
                    sI = i; sJ = j;
                }
            }
        }
        int count = 0;
        dfs(m,vis, w,h,count, sI, sJ);
        cout<<"Case "<<c<<": "<<count<<endl;
        c++;
    }
    return 0;
}