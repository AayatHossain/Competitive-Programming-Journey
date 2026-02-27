#include<bits/stdc++.h>
using namespace std;
const int ms = 1e5+1;
bitset<ms> bit;
vector<int> p(1e5+1);
signed main(){
    
    cin.tie(NULL);
    int n,q; cin>>n>>q;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        cin>>a[i];
      
    }
    
    bit.reset();
    bit[0]=1;
    for(int i = 0; i < n; i++){
        
        bit |= (bit<<a[i]);

    }

    p[0]=1;
    for(int i = 1; i < ms;i++){
        p[i]=p[i-1]+bit[i];
    }

    for(int i= 0; i < q; i++){
        int l,r; cin>>l>>r;
        cout<<p[r]-p[l-1]<<'\n';
    }


    return 0;
}