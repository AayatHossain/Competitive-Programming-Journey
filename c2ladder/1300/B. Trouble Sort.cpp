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

        int f1=0,f0=0;
        int sorted = 1;
        for(int i = 0; i < n; i++){
            if(b[i]==0)f0=1;
            if(b[i]==1)f1=1;
            if(i < n-1 && a[i] > a[i+1]){
                sorted = 0;
            }
        }
        
        if(sorted || (f1==1 && f0==1)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}