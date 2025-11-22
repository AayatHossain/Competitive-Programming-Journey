#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
bool ok(double m){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        cnt += a[i]/m;
    }
    return cnt >= k;
}
signed main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a.push_back(x);
    }
    double l = 1, r = 1e7+1;
    double m;
    for(int i = 0; i < 100; i++){
        m = l+(r-l)/2.0;
        if(ok(m)){
            l=m;
        }else{
            r=m;
        }
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    return 0;
}