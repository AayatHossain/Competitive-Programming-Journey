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
    build(2*i+2, mid+1, r);
    st[i] = st[2*i+1] + st[2*i + 2];
}
void sub(int t, int i, int l, int r){
    if(t==l && t==r){
        st[i] = 0; 
        a[l] = 0;
        return;
    }
    if(l==r && t != l){
        return;
    }
    int mid = l + (r-l)/2;
    if(t <= mid){
        sub(t, 2*i+1, l, mid);
    }else{
        sub(t, 2*i+2, mid+1, r);
    }
    st[i] = st[2*i+1] + st[2*i+2];
}
void add(int t,int v, int i, int l, int r){
    if(t==l && t==r){
        st[i] += v; 
        a[l] += v;
        return;
    }
    if(l==r && t != l){
        return;
    }
    int mid = l + (r-l)/2;
    if(t <= mid){
        add(t,v, 2*i+1, l, mid);
    }else{
        add(t,v, 2*i+2, mid+1, r);
    }
    st[i] = st[2*i+1] + st[2*i+2];
}
int sum(int i, int l, int r, int s, int e){
    if(l > e || r < s){
        return 0;
    }
    if(l >= s && r <= e){
        return st[i];
    }
    int mid = l + (r-l)/2;
    int v1 = sum(2*i+1, l, mid, s, e);
    int v2 = sum(2*i+2, mid+1, r, s, e);
    return v1+v2;
}
signed main(){
    int t; int c = 1;cin>>t;
    while(t--){
        int n, q; cin>>n>>q;
        for(int i = 0; i < n; i++)cin>>a[i];
        build(0, 0, n-1);

        cout<<"Case "<<c<<":"<<endl;
        for(int i =0; i < q; i++){
            int x; cin>>x;
            if(x==1){
                int s; cin>>s;
                cout<<a[s]<<endl;
                sub(s, 0, 0, n-1);

            }else if(x==2){
                int s, v; cin>>s>>v;
                add(s, v,0,0,n-1);
            }else{
                int s, e; cin>>s>>e;
                cout<<sum(0,0,n-1,s,e)<<endl;
            }
        }
        c++;
        a.clear();
        st.clear();
    }
}