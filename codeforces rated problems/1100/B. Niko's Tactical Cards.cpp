#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        vector<int> b(n+1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= n; i++){
            cin>>b[i];
        }
        vector<vector<int>> c(2, vector<int>(n+1,0));
        for(int i = 1; i <= n; i++){
            int v1 = c[0][i-1] - a[i];
            int v2 = b[i] - c[1][i-1];
            c[0][i] = max(v1,v2);

             v1 = c[1][i-1] - a[i];
             v2 = b[i] - c[0][i-1];
            c[1][i] = min(v1,v2);
        }
        cout<<max(c[0][n], c[1][n])<<endl;

    }
    return 0;
}