#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
struct node{
    int leftmost,rightmost,leftmostfreq,rightmostfreq, ans;
    node(){

    }
    node(int lm,int rm,int lmf,int rmf, int answer){
        leftmost = lm;
        rightmost = rm;
        leftmostfreq = lmf;
        rightmostfreq = rmf;
        ans = answer;
    }
};
vector<node> st(4*N);
vector<int> a(N);

void merge(node &curr, node &left, node &right){

    if(left.leftmost == right.rightmost){
        curr.leftmost = left.leftmost;
        curr.rightmost = right.rightmost;
        curr.leftmostfreq = left.leftmostfreq + right.rightmostfreq;
        curr.rightmostfreq = left.leftmostfreq + right.rightmostfreq;
        curr.ans = left.leftmostfreq + right.rightmostfreq;

    }else if(left.rightmost == right.leftmost && left.rightmost != right.rightmost){

        curr.leftmost = left.leftmost;
        curr.rightmost = right.rightmost;
        curr.leftmostfreq = left.leftmostfreq + right.leftmostfreq;
        curr.rightmostfreq = right.rightmostfreq;
        curr.ans = max(left.leftmostfreq + right.leftmostfreq, right.rightmost);

    }else if(right.rightmost == left.rightmost && left.leftmost != right.rightmost){

        curr.leftmost = left.leftmost;
        curr.rightmost = right.rightmost;
        curr.leftmostfreq = left.leftmostfreq;
        curr.rightmostfreq = left.rightmostfreq + right.rightmostfreq;
        curr.ans = max(left.leftmostfreq , left.rightmostfreq + right.rightmostfreq);

    }else if(left.rightmost == right.leftmost && left.leftmost != right.rightmost){
        curr.leftmost = left.leftmost;
        curr.rightmost = right.rightmost;
        curr.leftmostfreq = left.leftmostfreq;
        curr.rightmostfreq = right.rightmostfreq;
        curr.ans = max(left.ans , right.ans);
    }else{
        curr.leftmost = left.leftmost;
        curr.rightmost = right.rightmost;
        curr.leftmostfreq = left.leftmostfreq;
        curr.rightmostfreq = right.rightmostfreq;
        curr.ans = max(left.ans , right.ans);
    }

}

void build(int i, int l, int r){
    if(l==r){
        int curr = a[l];
        st[i] = node(curr,curr,1,1,1);
        return;
    }
    int m = l+(r-l)/2;
    build(2*i, l,m);
    build(2*i+1, m+1,r);
    merge(st[i], st[2*i], st[2*i+1]);
}

signed main(){
    int n,q; cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i = 0; i < q; i++){
        int s,e; cin>>s>>e;
        cout<<get()<<endl;
    }
    int x;cin>>x;
}