#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int a,b,c,m; cin>>a>>b>>c>>m;
        int lab = lcm(a,b);
        int lbc = lcm(b,c);
        int lca = lcm(c,a);
        int labc = lcm(a,lcm(b,c));

        int ab = m/lab;
        int bc = m/lbc;
        int ca = m/lca;
        int abc = m/labc;

        int alice = 6*(m/a) - 3*ab - 3*ca + 2*abc;
        int bob = 6*(m/b) - 3*ab - 3*bc + 2*abc;
        int carol = 6*(m/c) - 3*ca - 3*bc + 2*abc;

        cout<<alice<<" "<<bob<<" "<<carol<<endl;
    }
    
}