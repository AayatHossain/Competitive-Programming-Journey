#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        // vector<int> b = a;
        if(n&1){
            int f = 1;
            for(int i = 1; i < n; i++){
                if(a[i] <= a[i-1]){
                    f = 0; break;
                }
            }
            if(!f){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}