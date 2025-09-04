#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int a,b,c; cin>>a>>b>>c;
    vector<int> d;
    for(int i = 1; i*i <= c; i++){
        if(c%i==0){
            if(c/i == i){
                d.push_back(i);
            }else{
                d.push_back(i);
                d.push_back(c/i);
            }
        }
    }
    sort(d.begin(),d.end());
    int cnt = 0;
    for(auto x: d){
        // cout<<x<<" ";
        if(x >= a && x <= b)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}