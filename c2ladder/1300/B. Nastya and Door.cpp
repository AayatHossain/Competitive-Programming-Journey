#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i= 0; i < n; i++)cin>>a[i];
        
        vector<int> p(n+1,0);
        for(int i = 1; i < n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                p[i+1] = p[i] + 1;
                
            }else{
                p[i+1] = p[i];
            }
        }
        p[n]=p[n-1];
        // for(int i = 1; i <= n; i++){
        //     cout<<p[i]<<" ";
        // }
        // cout<<endl;

        int l = -1;
        int mx = LLONG_MIN;
        for(int i = 1; i+k-2 < n; i++){
            int d = p[i+k-2] - p[i];
            if(d > mx){
                mx = d;
                l = i;
            }
        }
        cout<<mx+1<<" "<<l<<'\n';

    }
    return 0;
}