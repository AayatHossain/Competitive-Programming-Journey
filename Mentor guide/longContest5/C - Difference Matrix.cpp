#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int v = 1;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<v<<" ";
                v+=2;
                if(v>n*n){
                    v = 2;
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}