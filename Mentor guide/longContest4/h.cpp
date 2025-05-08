#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
vector<int> a(N, 0);
vector<int>lazy(4*N, 0);
struct node{
    int z,o,t;
    node(){
        z = 0; o = 0; t = 0;
    }
    node(int i,int j, int k){
        z = i; o = j; t = k;
    }
};
vector<node>st(4*N);
node merge(node left, node right){
    node curr;
    curr.z = left.z + right.z;
    curr.o = left.o + right.o;
    curr.t = left.t + right.t;
    return curr;
}
void propagateChild(int i, int val){
    lazy[i] += val;
    node curr = st[i];
    if(val%3==1){
        int temp = curr.z;
        curr.z = curr.t;
        curr.t = curr.o;
        curr.o = temp;
    }else if(val%3==2){
        int temp = curr.z;
        curr.z = curr.o;
        curr.o = curr.t;
        curr.t = temp;
    }
    st[i] = curr;
}
void propagate(int i, int val){
    propagateChild(2*i, val);
    propagateChild(2*i+1, val);
    lazy[i] = 0;
    return;
}
void build(int i, int l, int r){
    if(l==r){
        st[i] = node(1,0,0);
        return;
    }
    int m = l+(r-l)/2;
    build(2*i, l,m);
    build(2*i+1, m+1, r);
    st[i] = merge(st[2*i], st[2*i+1]);
}
void update(int i, int l, int r, int s, int e){
    if(l > e || r < s){
        return;
    }
    node curr = st[i];

    if(l >= s && r <= e){
        lazy[i]++;
        int temp = curr.z;
        curr.z = curr.t;
        curr.t = curr.o;
        curr.o = temp;
        
        st[i] = curr;
        return;
    }
    if(lazy[i] > 0){
        propagate(i, lazy[i]);
    }
    int m = l+(r-l)/2;
    update(2*i,l,m,s,e);
    update(2*i+1, m+1,r,s,e);
    st[i] = merge(st[2*i], st[2*i+1]);
}
node get(int i, int l, int r, int s, int e){
    if(l > e || r < s){
        return node(0,0,0);
    }
    if(l >= s && r <= e){
        return st[i];
    }
    if(lazy[i] > 0){
        propagate(i, lazy[i]);
    }
    int m = l+(r-l)/2;
    node n1 = get(2*i,l,m,s,e);
    node n2 = get(2*i+1, m+1,r,s,e);
    node finalnode = merge(n1,n2);
    return finalnode;
}


signed main(){
    int n,q;cin>>n>>q;
    build(1,1,n);
    for(int i = 0; i< q; i++){
        int x,y,z; cin>>x>>y>>z;
        y++;z++;
        if(x==0){
            update(1,1,n,y,z);
        }else{
            cout<<get(1,1,n,y,z).z<<endl;
        }
    }
    
}