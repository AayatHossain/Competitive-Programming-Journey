#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n, k, p;
        cin>>n>>k>>p;
        int op = abs(k)/p;
        if(op > n || (op >= n && abs(k)%p > 0)){
            cout<<-1<<endl;continue;
        }else{
            if(abs(k)%p > 0){
                op++;
            } 
            cout<<op<<rendl;
        }
    }
}