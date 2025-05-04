#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
struct node{
    int val;
    int max;
    int best;
    node(int v){
        val = v;
        max = v;
        best = v;
    }
    node(){

    }
};
vector<int> a(N);
vector<node> st(4*N);
int n,q;
void merge(int i, node left, node right){
    st[i].best = max(left.best, max(right.best, left.max + right.max));
    st[i].max = max(left.max, right.max);
}
void build(int i, int l, int r){
    if(l==r){
        st[i] = node(a[l]);
        return;
    }
    int m = l+(r-l)/2;
    build(2*i,l,m);
    build(2*i+1,m+1,r);
    st[i].val = 0;
    merge(i, st[2*i], st[2*i+1]);
}
void update(int i, int l, int r, int index, int val){
    if(l==r && index == l){
        st[i] = node(val);
        return;
    }
    int m = l+(r-l)/2;
    if(index<=m){
        update(2*i, l,m,index,val);
    }else{
        update(2*i+1,m+1,r,index,val);
    }
    merge(i,st[2*i],st[2*i+1]);
}
node get(int i, int l, int r, int s, int e){
    if(l > e || r <s){
        return node(-1e5);
    }
    if(l>=s && r<=e){
        return st[i];
    }
    int m = l+(r-l)/2;
    node n1 = get(2*i, l,m,s,e);
    node n2 = get(2*i+1,m+1,r,s,e);
    // node finalNode = node((n1.best, max(n2.best, n1.max+n2.max)));
    node finalNode = node();
    finalNode.max = max(n1.max, n2.max);
    finalNode.best = max(n1.best, max(n2.best, n1.max+n2.max));
    return finalNode;
}
signed main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    build(1,1,n);
    cin>>q;
    for(int i = 0; i < q; i++){
        char c; cin>>c;
        if(c=='U'){
            int index, val; cin>>index>>val;
            update(1,1,n,index,val);
        }else{
            int s, e; cin>>s>>e;
            cout<<get(1,1,n,s,e).best<<endl;
        }
    }

}