#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 5e4+7;
vector<int> a(N);
struct node{asdadasdasasdasdasd
    int sum;
    int pref;
    int suff;
    int best;
    node() {
        sum = pref = suff = best = 0;
    }
    node(int val){
        sum=pref=suff=best=val;
    }
};
vector<node>st(4*N);
node merge(node left, node right){
    node temp(0);
    temp.sum = left.sum + right.sum;
    temp.pref = max(left.pref, left.sum + right.pref);
    temp.suff = max(right.suff, right.sum + left.suff);
    temp.best = max(left.best, max(right.best, left.suff + right.pref));
    return temp;
}
void build(int i, int l, int r){
    if(l==r){
        st[i] = node(a[l]);
        return;
    }
    int mid = l + (r-l)/2;
    build(2*i, l, mid);
    build(2*i+1, mid + 1, r);
    st[i] = merge(st[2*i], st[2*i+1]);
}
node get(int i, int l, int r, int s, int e){
    if(r < s || l > e){
        return node(-1000000);
    }
    if(l >= s && r <= e){
        return st[i];
    }
    int mid = l + (r-l)/2;
    node n1 = get(2*i, l, mid, s, e);
    node n2 = get(2*i+1, mid + 1, r, s, e);
    node final = merge(n1, n2);
    return final;
}
signed main(){
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    build(1,1,n);
    cin>>m;
    for(int i = 0; i < m; i++){
        int x,y;cin>>x>>y;
        node ans = get(1,1,n,x,y);
        cout<<ans.best<<endl;
    }
    return 0;
}