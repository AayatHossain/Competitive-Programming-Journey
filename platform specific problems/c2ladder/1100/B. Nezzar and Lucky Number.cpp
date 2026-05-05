#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,d; cin>>n>>d;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            int v;
            int f=0;
            for(int j = 1; j <= x && j*d <= x; j++){
                v = d*j;
                int l = x - v;
                if(l%10==0 || x%v==0){
                    f = 1; break;
                }

            }
            if(f){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }   
    }
    return 0;
}