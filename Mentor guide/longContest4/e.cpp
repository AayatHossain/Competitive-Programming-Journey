#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
struct node{
    int val=0;
    int a=0;
    int b=0;
    int c=0;
    int val(int i){
        return a*i*i + b*i + c;
    }
    node(int v){
        val = v;
    }
    node(){
        a=b=c=0;
    }
};
int n,q;
vector<int>a(N);
vector<node>st(4*N);
void build(int i, int l, int r){
    if(l==r){
        st[i] = node(a[l]);
        return;
    }
    int mid = l+(r-l)/2;
    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);
    st[i] = 0;
}
void update(int i, int l, int r, int s, int e, int v, int begL){
    if(l >e || r<s){
        return;
    }
    if(l>=s && r<=e){
        st[i].a++;
        st[i].b += (v-begL);
        st[i].c += (v-begL)*(v-begL);
        return;
    }
    int mid = l+(r-l)/2;
    update(2*i+1, l,mid,s,e,v,begL);
    update(2*i+2, mid+1,r,s,e,v,begL);
}
int get(int i, int l,int r,int index){
    if(l==r && l==index){
        int sum = st[i].val;
    }
}
signed main(){
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    build();
    for(int i = 0; i < q; i++){
        int x;cin>>x;
        if(x==1){
            int l,r,v; cin>>l>>r>>x;
            update();
        }else{
            int indx;
            cout<<get()<<endl;
        }
    }
    return 0;
}