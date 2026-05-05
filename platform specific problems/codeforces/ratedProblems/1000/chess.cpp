#include<bits/stdc++.h>
using namespace std;
#define int long long
int findCost(vector<vector<int>> &a, int i, int j, int n, int m){
    int x = i, y = j;
    int cost = 0;
    while(x >= 0 && y < m){
        cost += a[x][y];
        x--;y++;
    }
    x = i, y = j;
    while(x >= 0 && y >= 0){
        cost += a[x][y];
        x--;y--;
    }
    x = i, y = j;
    while(x < n && y >= 0){
        cost += a[x][y];
        x++;y--;
    }
    x = i, y = j;
    while(x < n && y < m){
        cost += a[x][y];
        x++;y++;
    }
    return cost - 3*a[i][j];
}
signed main()
{
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>a[i][j];
            }
        }
        int cost = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int c = findCost(a,i,j, n, m);
                cost = max(cost, c);
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}