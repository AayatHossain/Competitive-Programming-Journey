#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
vector<int> a(N);
struct node{
    int gcd,min,count;
    node(){

    }
    node(int g,int m, int c){
        gcd = g; min = m; count = c;
    }
};
vector<node> st(4*N);
node merge(node left, node right){
    node curr;
    curr.min = min(left.min, right.min);
    curr.gcd = gcd(left.gcd, right.gcd);
    if(left.min==right.min){
        curr.count = left.count + right.count;
    }else if(left.min < right.min){
        curr.count = left.count;
    }else{
        curr.count = right.count;
    }
    return curr;
}

void build(int i, int l, int r){
    if(l==r){
        st[i] = node(a[l],a[l],1);
        return;
    }
    int mid = l+(r-l)/2;
    build(2*i, l,mid);
    build(2*i+1, mid+1, r);
    st[i] = merge(st[2*i], st[2*i+1]);
}

node get(int i, int l, int r, int s, int e){
    if(l > e || r < s){
        return node(0,1e10,0);
    }
    if(l >= s && r <= e){
        return st[i];
    }
    int mid = l+(r-l)/2;
    node left = get(2*i, l,mid,s,e);
    node right = get(2*i+1, mid+1,r,s,e);
    node finalNode = merge(left, right);
    return finalNode; 
}

signed main(){
    int n,q;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    build(1,1,n);
    cin>>q;
    for(int i = 0; i < q; i++){
        int s,e; cin>>s>>e;
        node res = get(1,1,n,s,e);
        if(res.gcd==res.min){
            cout<<e-s+1-res.count<<endl;
        }else{
            cout<<e-s+1<<endl;
        }
    }
}