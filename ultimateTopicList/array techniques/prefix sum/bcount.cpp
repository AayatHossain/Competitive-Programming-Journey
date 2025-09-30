#include<bits/stdc++.h>
using namespace std;
signed main(){
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");

    int n,q; fin>>n>>q;
    vector<vector<int>> a(n+1, vector<int>(4, 0));
    for(int i = 1; i <= n; i++){
        int x; fin>>x;
        a[i][x]++;
        if(i > 1){
            a[i][1]=a[i-1][1]+a[i][1];
            a[i][2]=a[i-1][2]+a[i][2];
            a[i][3]=a[i-1][3]+a[i][3];
        }
    }
    for(int i = 1; i <= q; i++){
        int l,r; fin>>l>>r;
        int v1 = a[r][1]-a[l-1][1];
        int v2 = a[r][2]-a[l-1][2];
        int v3 = a[r][3]-a[l-1][3];
        fout<<v1<<" "<<v2<<" "<<v3<<'\n';
    }

    return 0;
}