
#include<bits/stdc++.h>
using namespace std;

void addEdge(int s, int d, int wt, vector<vector<int>> &g){
    g[s][d] = wt;
    g[d][s] = wt;
}

int main(){
    int n = 8;
    vector<vector<int>> g(n, vector<int>(n,0));
    addEdge(1,2,1, g);
    addEdge(3,4,1, g);
    addEdge(6,7,1, g);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}