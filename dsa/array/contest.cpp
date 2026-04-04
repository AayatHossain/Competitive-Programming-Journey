#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        // int n; cin>>n;
        // vector<int> a(n+1);
        // int h1 = n/2;
        // int h2 = h1+1;
        // a[h1] = 2;
        // a[h2] = 3;
        // int c = 6;
        // for(int i = h2+1; i <= n; i++){
        //     a[i] = c;
        //     c*=2;
        // }
        // c = 4;
        // for(int i = h1-1; i >= 1; i--){
        //     a[i] = c;
        //     c*=2;
        // }
        // for(int i = 1; i <= n; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // vector<int> a = {134, 67, 69, 207, 414};
        // for(int i = 1; i < a.size(); i++){
        //     cout<<gcd(a[i],a[i-1])<<" ";
        //     cout<<endl;
        // }
        //     cout<<134/67<<endl;
        int c = 69*3;
        for(int i = 0; i < 50; i++){
            c*=2;
        }
        cout<<c<<endl;

    }
    
    return 0;
}