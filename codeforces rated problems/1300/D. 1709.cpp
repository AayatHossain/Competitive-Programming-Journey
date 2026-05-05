#include<bits/stdc++.h>
using namespace std;



signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    set<int> s;
    for(int i =0; i < n; i++){
        if(a[i]==-1)continue;
        s.insert(a[i]);
    }

    set<int> missing;
    for(int i = 1; i <= n; i++){
        if(s.find(i) == s.end()){
            missing.insert(i);
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i]==-1){
            int v = *missing.begin();
            a[i] = v;
            missing.erase(v);
        }
    }
    // for(auto x: missing){
    //     cout<<x<<" ";
    // }
    if(missing.size() > 0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    

    
    return 0;
}