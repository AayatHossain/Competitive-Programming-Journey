#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int j = n-1;
        vector<int>b;
        vector<int>pm(n);
        pm[0]=a[0];
        for(int i = 1; i < n; i++){
            pm[i]=max(pm[i-1],a[i]);
        }
        int mx = n;
        for(int i=n-1; i >= 0; i--){
            if(a[i]==mx){
                for(int k=i; k <= j; k++){
                    b.push_back(a[k]);
                }
                
                j=i-1;
                if(j>=0)mx=pm[j];
            }
        }
        for(auto x: b){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
}