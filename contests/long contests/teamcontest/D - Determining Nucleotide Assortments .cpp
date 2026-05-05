#include<bits/stdc++.h>
using namespace std;
struct node{
    int T = 0, G = 0, C = 0, A = 0;
};
struct node1{
    string name;
    int val = 0;
    int priority = 0;

    static bool compare(const node1 &a, const node1 &b){
        if(a.val != b.val){
            return a.val > b.val;
        }else{
            return a.priority > b.priority;
        }
    }
};
signed main(){
    string s; cin>>s;
    int n = s.size();
    vector<node> a(n+1);
    node temp;
    for(int i = 1; i <= n; i++){
        if(s[i-1]=='T')temp.T++;
        if(s[i-1]=='G')temp.G++;
        if(s[i-1]=='C')temp.C++;
        if(s[i-1]=='A')temp.A++;
        a[i] = temp;
        // cout<<a[i].T<<a[i].G<<a[i].C<<" "<<a[i].A;
    }
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        node n1 = a[l-1];
        node n2 = a[r];
        // cout<<n1.A<<" "<<n1.T<<" "<<n1.G<<" "<<n1.C<<endl;
        // cout<<n2.A<<" "<<n2.T<<" "<<n2.G<<" "<<n2.C<<endl;
        node1 na = {"A", n2.A - n1.A, 4};
        node1 nt = {"T", n2.T - n1.T, 3};
        node1 ng = {"G", n2.G - n1.G, 2};
        node1 nc = {"C", n2.C - n1.C, 1};
        vector<node1> ans;
        ans.push_back(na);
        ans.push_back(nt);
        ans.push_back(ng);
        ans.push_back(nc);
        sort(ans.begin(),ans.end(), node1::compare);
        for(auto x: ans){
            cout<<x.name;
        }
        cout<<endl;
    }
}