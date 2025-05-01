#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
vector<int> segTree(4*N);
vector<int> a(N);

void build(int i, int l, int r){
    if(l==r){
        segTree[i] = a[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    segTree[i] = min(segTree[2*i+1], segTree[2*i+2]);
}
int query(int i, int l, int r, int s, int e){
    if(l > e || r < s){
        return LLONG_MAX;
    }
    if(l>=s && r <= e){
        return segTree[i];
    }
    int mid = l+(r-l)/2;
    int v1 = query(2*i+1,l,mid,s,e);
    int v2 = query(2*i+2,mid+1,r,s,e);
    return min(v1,v2);
}

signed main(){
    int t; int c = 1; cin>>t;
    while(t--){
        string s; getline(cin, s);
        int n, q; cin>>n>>q;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        build(0, 0, n-1);
        cout<<"Case "<<c<<":"<<endl;
        for(int i = 0;i < q; i++){
            int x,y; cin>>x>>y;
            x--;y--;
            int ans = query(0, 0, n-1, x, y);
            cout<<ans<<endl;
        }
        c++;
        a.clear();
        segTree.clear();
    }
}