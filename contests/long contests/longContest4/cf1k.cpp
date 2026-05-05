#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isSqr(int n){
    int m = sqrt(n);
    return m*m == n;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        vector<int>diff(n);
        map<int,int> m;
        for(int i = 0; i < n ; i++){
            diff[i] = a[i] - i;
            m[diff[i]]++;
        }
        int count = 0;
        for(auto x: m){
            count += (x.second*(x.second-1))/2;
        }
        cout<<count<<endl;
        
    }
    return 0;
}