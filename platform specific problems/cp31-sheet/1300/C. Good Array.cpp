#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second=i;
        
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < n; i++){
        
        if(!i){
            p[i]=a[i].first;
        }else{
            p[i]=p[i-1]+a[i].first;
        }
    }
    vector<int> res;
    for(int i = 0; i < n; i++){
        if(i < n-1){
            if(n-2 >= 0 && p[n-2]-a[i].first==a[n-1].first){
                // cout<<i+1<<" ";
                res.push_back(a[i].second+1);
            }
        }else{
            if(i-2 >= 0 && i-1>=0 && p[i-2]==a[i-1].first){
                res.push_back(a[i].second+1);
            }
        }
    }
    cout<<res.size()<<endl;
    for(auto x: res){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}