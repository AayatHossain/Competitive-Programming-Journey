#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
vector<int>a(N);
vector<int>segTree(4*N);
void build(int i, int l, int r){
    if(l==r){
        segTree[i] = a[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}
int query(int i, int l, int r, int s, int e){
    if(l >= s && r <= e){
        return segTree[i];
    }
    
    if(e < l || s > r){
        return 0;
    }
    int mid = l + (r - l)/2;
    int s1 = query(2*i+1, l, mid, s, e);
    int s2 = query(2*i+2, mid + 1, r, s, e);
    return s1 + s2;
}
signed main(){
    int n,q;cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    build(0, 0, n-1);
    for(int i = 0; i < q; i++){
        int x, y; cin>>x>>y;
        int sum = query(0, 0, n-1, --x,--y);
        cout<<sum<<endl;
    }
    return 0;
}