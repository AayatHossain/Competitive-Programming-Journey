#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m+1);
    for(int i = 0; i < m+1; i++){
        cin>>a[i];
    }
    int f = a[m];
    int count = 0;
    for(int i = 0; i < m; i++){
        int v = f^a[i];
        // cout<<v<<endl;
        int ones = __popcount(v);
        // cout<<ones<<endl;
        if(ones <= k){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}