#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int a[n+1][m+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m; j++){
                cin>>a[i][j];
            }
        }
        int s = 0;
        for(int i = 1; i <= n/2; i++){
            for(int j = 1; j <= m/2; j++){
                int c1 = a[i][j];
                int c2 = a[i][m-j+1];
                int c3 = a[n-i+1][j];
                int c4 = a[n-i+1][m-j+1];
                
                int d1 = abs(c2-c1)+abs(c3-c1)+abs(c4-c1);
                int d2 = abs(c1-c2)+abs(c3-c2)+abs(c4-c2);
                int d3 = abs(c1-c3)+abs(c2-c3)+abs(c4-c3);
                int d4 = abs(c1-c4)+abs(c2-c4)+abs(c3-c4);

                s += min(d1,min(d2,min(d3,d4)));
            }
        }
        if(n%2==1){
            for(int j = 1; j <= m/2; j++){
                int c1 = a[n/2 + 1][j];
                int c2 = a[n/2 + 1][m-j+1];
                s += abs(c1-c2);
            }
        }
        if(m%2==1){
            for(int i = 1; i <= n/2; i++){
                int c3 = a[i][m/2 + 1];
                int c4 = a[n-i+1][m/2 + 1];
                s += abs(c3-c4);
            }
        }
        cout<<s<<endl;
    }
}