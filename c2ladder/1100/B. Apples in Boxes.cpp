#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        int s = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            s+=a[i];
        }
        sort(a.begin(),a.end());
        a[n-1]--;
        sort(a.begin(),a.end());
        int diff = a[n-1]-a[0];
        if(diff <= k){
            if(s&1){
                cout<<"Tom"<<endl;
            }else{
                cout<<"Jerry"<<endl;
            }
        }else{
            cout<<"Jerry"<<endl;
        }
    }
    return 0;
}