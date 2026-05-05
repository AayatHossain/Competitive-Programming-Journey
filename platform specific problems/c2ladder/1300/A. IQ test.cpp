#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<pair<int,int>> odd;
    vector<pair<int,int>> even;
    for(int i = 0; i < n; i++){
        if(a[i] & 1){
            odd.push_back({a[i],i+1});
        }else{
            even.push_back({a[i],i+1});
        }
    }
    if(odd.size()==1){
        cout<<odd[0].second<<endl;
    }else{
        cout<<even[0].second<<endl;
    }
    return 0;
}