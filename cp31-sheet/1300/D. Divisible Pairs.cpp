#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,x,y; cin>>n>>x>>y;
        map<int,int> m1;
        map<int,int> m2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int val; cin>>val;
            int v = val%y;
            int v1 = m2[v];
            int v2 = 0;
            int c1 = v1+v2;
            m2[v]++;

            v = val%x;
            int c2 = m1[x-v];
            m1[v]++;

            ans += min(c1,c2);
        }
        cout<<ans<<endl;
    }
    return 0;
}