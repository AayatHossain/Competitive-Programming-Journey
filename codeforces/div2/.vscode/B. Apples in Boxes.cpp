#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        int mn = a[0];
        int mx = a[n-1]-1;
        int d = mx - mn;
        if(d > k){
            cout<<"Jerry"<<endl;
        }else{
            if(sum&1){
                cout<<"Tom"<<endl;
            }else{
                cout<<"Jerry"<<endl;
            }
        }
    }
    return 0;
}