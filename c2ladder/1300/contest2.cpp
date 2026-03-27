#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin>>n>>m;
    vector<int> a(n);
    multiset<int> s;
    for(int i = 0; i < n; i++ ){
        cin>>a[i];
        s.insert(a[i]);
    }
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        b[i] = (x+y-1)/y;
    }

    sort(b.rbegin(),b.rend());

    // for(auto x: s){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    // for(auto x: b){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    

    int c = 0;
    for(int i = 0; i < m; i++){
        if(s.empty()){
            break;
        }
        int v = b[i];
        auto it = s.lower_bound(v);
        if(it != s.end()){
            c++;
            s.erase(it);
        }
    }
    cout<<c<<endl;

    

    return 0;
}