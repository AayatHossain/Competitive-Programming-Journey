#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n; cin>>n;
    
    for(int i = 0 ;i < n; i++){
        int x; cin>>x;
        int c = 0;
        for(int j = 1; j*j <= x; j++){
            if(x%j == 0){
                if(x/j == j){
                    c++;
                }else{
                    c+=2;
                }
                // cout<<j<<" "<<x/j<<endl;
            }
           
            
        }
        cout<<c<<endl;
    }
    return 0;
}