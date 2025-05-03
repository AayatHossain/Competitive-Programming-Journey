#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
vector<int> a(N);
vector<int> st(4*N);
void build(int i, int l, int r){
    if(l==r){
        st[i] = a[l]; return;
    }
    int mid = l + (r-l)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid + 1, r);
    st[i] = 0;
}
void addRange(int i, int l, int r, int s, int e, int val){
    if(s > e){
        return;
    }
    if(s==l && e==r){
        st[i] += val;
        return;
    }
    int mid = l + (r-l)/2;
    
}
signed main(){
    int n,q; cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    build(0,0,n-1);
    for(int i = 0; i < q; i++){
        int x; cin>>x;
        if(x==1){
            //update
            int s,e,v; cin>>s>>e>>v;
            s--;e--;
            addRange(0,0,n-1,s,e,v);
        }else{
            int s; cin>>s; s--;
            cout<<getVal(0,0,n-1,s)<<endl;
        }
    }
    return 0;
}