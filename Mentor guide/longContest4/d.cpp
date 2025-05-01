#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4+7;
vector<int> segTree(4*N);
vector<int> segTree2(4*N);
vector<int> a(N);
int n,q;

void build(int i, int l, int r){
    if(l==r){
        segTree[i] = a[l];
        segTree2[i] = a[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    segTree2[i] = max(segTree[i],max(segTree[2*i+1] , segTree[2*i+2]));
}
int query(int i, int l, int r, int s, int e){
    if(l > e || r < s){
        return LLONG_MIN;
    }
    if(l>=s && r <= e){
        return segTree2[i];
    }
    int mid = l+(r-l)/2;
    int v1 = query(2*i+1,l,mid,s,e);
    int v2 = query(2*i+2,mid+1,r,s,e);
    return max(v1,v2);
}

signed main(){
    
        
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        cin>>q;
        build(0, 0, n-1);

        for(int i = 0;i < q; i++){
            int x,y; cin>>x>>y;
            x--;y--;
            int ans = query(0, 0, n-1, x, y);
            cout<<ans<<endl;
        }
        
    
}