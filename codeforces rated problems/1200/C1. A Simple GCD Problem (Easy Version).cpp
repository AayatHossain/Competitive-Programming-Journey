#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++)cin>>a[i];
        for(int i = 0; i < n; i++)cin>>b[i];

        int cnt = 0;
        if(__gcd(a[0],a[1]) < a[0]){
            cnt++;
        }
        if(__gcd(a[n-2],a[n-1]) < a[n-1]){
            cnt++;
        }
        for(int i = 1; i < n-1; i++){
            if(lcm(__gcd(a[i],a[i-1]), __gcd(a[i],a[i+1])) < a[i]){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}