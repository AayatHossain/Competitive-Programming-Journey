#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n, k;cin>>n>>k;
        if(k & 1){
            for(int i = 1; i <= n; i++){
                if(i == n){
                    cout<<n-1;
                }else{
                    cout<<n<<" ";
                }
            }
        }else{
            for(int i = 1; i < n; i++){
                if(i == n-1){
                    cout<<n<<" ";
                }else{
                    cout<<n-1<<" ";
                }
            }
            cout<<n-1;
        }
        cout<<endl;


    }
    return 0;
}