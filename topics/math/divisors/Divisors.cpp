#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a;
    for(int i = 1; i*i <= n; i++){
        if(n%i==0){
            if(n/i == i){
                a.push_back(i);
            }else{
                a.push_back(i);
                a.push_back(n/i);
            }
        }
    }
    sort(a.begin(),a.end());
    for(auto x: a){
        cout<<x<<endl;
    }
    return 0;
}