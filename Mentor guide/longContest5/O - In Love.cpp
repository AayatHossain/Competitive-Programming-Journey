#include<bits/stdc++.h>
using namespace std;
multiset<int> l;
multiset<int> r;
string add(int a, int b){
    l.insert(a);
    r.insert(b);
    int leastRight = *r.begin();
    int mostLeft = *l.rbegin();
    // for(auto x: l){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x: r){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    if(leastRight < mostLeft){
        return "YES";
    }else{
        return "NO";
    }
}
string sub(int a, int b){
    auto it1 = l.find(a);
    auto it2 = r.find(b);
    l.erase(it1);
    r.erase(it2);
    if(l.empty() || r.empty()){
        return "NO";
    }
    int leastRight = *r.begin();
    int mostLeft = *l.rbegin();
    // for(auto x: l){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x: r){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    if(leastRight < mostLeft){
        return "YES";
    }else{
        return "NO";
    }
}
signed main(){
    int q;cin>>q;
    // cout<<"Start"<<endl;
    while(q--){
        char c; int a,b;
        cin>>c>>a>>b;
        if(c=='+'){
            string exits = add(a,b);
            cout<<exits<<endl;
        }else{
            string exits = sub(a,b);
            cout<<exits<<endl;
        }
    }
    return 0;
}