#include<bits/stdc++.h>
using namespace std;
#define int long long

void f(int as, int bs, int a, int b, set<int> &s){
    //bro this is not gpt wrote it for myself promise

    //aw = as - bb + ab;
    // or,  ab = aw - (as - bb);
    for(int i = 0; i <= as; i++){
        int ab = a - (as - i);
        if(ab >= 0 && ab <= bs){
            s.insert((ab + i));
        }
    }

    //bw = bs - ab + bb;
    //or, bb = bw - (bs - ab)
    for(int i = 0; i <= bs; i++){
        int bb = b - (bs - i);
        if(bb >= 0 && bb <= as){
            s.insert((bb + i));
        }
    }
}

signed main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        set<int> s;
        int as = (a+b+1)/2;
        int bs = (a+b)/2;
        f(as,bs,a,b, s);
        f(bs,as,a,b, s); 
        cout<<s.size()<<endl;
        for(auto x: s){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}