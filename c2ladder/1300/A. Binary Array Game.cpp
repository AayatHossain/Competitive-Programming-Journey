#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n+1,0);
        
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            a[x]++;
        }
        int mex=0;
        while(a[mex]){
            mex++;
        }
        cout<<min(mex,k-1)<<endl;
    }
    return 0;
}
