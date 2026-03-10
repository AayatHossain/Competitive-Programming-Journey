#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k,t; cin>>n>>m>>k>>t;
    vector<int> p(n+1,0);
    for(int i = 0; i < m; i++){
        int x; cin>>x;
        p[x] = 1;
    }
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + p[i];
    }
    for(int i = 0; i < k; i++){
        int l,r; cin>>l>>r;
        int d = p[r] - p[l-1];
        if(d >= t){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }

    return 0;
}