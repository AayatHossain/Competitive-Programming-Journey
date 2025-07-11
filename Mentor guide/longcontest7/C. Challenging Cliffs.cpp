#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i  = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int d = LLONG_MAX/2;
        for(int i = 1; i < n; i++){
            int v = abs(a[i] - a[i-1]);
            d = min(v,d);
        }
        // cout<<d<<endl;
        int l = -1, r = -1;
        for(int i = 1; i < n; i++){
            if(abs(a[i] - a[i-1])==d){
                l = i-1; r = i;
                break;
            }    
        }
        cout<<a[l]<<" ";
        for(int i = r+1; i < n; i++){
            cout<<a[i]<<" ";
        }
        for(int i = 0; i < l; i++){
            cout<<a[i]<<" ";
        }
        cout<<a[r]<<endl;
        
        // cout<<endl;
        
    }
}