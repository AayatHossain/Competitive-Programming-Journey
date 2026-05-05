#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        // vector<int> a(n);
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            if(i&1){
                cout<<-abs(x)<<" ";
            }else{
                cout<<abs(x)<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}