#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 5e4+7;
vector<int> a(N);
struct node{
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
    temp.sum = left.sum + right.sum;//curr sum
    temp.pref = max(left.pref, left.sum + right.pref);  //max prefix of left or from left sum to right prefix
    temp.suff = max(right.suff, right.sum + left.suff); //max suffix of right or from right sum to left suffix
    temp.best = max(left.best, max(right.best, left.suff + right.pref)); //lef.suff + right.pref will also act like leftsum plus right sum if its the max value. so we dont need to write it seperately
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
    node final = merge(n1, n2); //best from left and right taken.
    return final;
}
void update(int i, int l, int r, int target, int val){
    if(l==r && target==l){
        st[i] = node(val);
        return;
    }
    if(l==r && target != l){
        return;
    }
    int mid = l+(r-l)/2;
    if(target<=mid){
        update(2*i, l, mid, target, val);
    }else{
        update(2*i+1, mid + 1, r, target, val);
    }
    st[i] = merge(st[2*i], st[2*i+1]);
}
signed main(){
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    build(1,1,n);
    cin>>m;
    for(int i = 0; i < m; i++){
        int x;cin>>x;
        if(x==1){
            int y,z; cin>>y>>z;
            node ans = get(1,1,n,y,z);
            cout<<ans.best<<endl;
        }else{
            int target, val; cin>>target>>val;
            update(1,1,n,target,val);
        }
    }
    return 0;
}