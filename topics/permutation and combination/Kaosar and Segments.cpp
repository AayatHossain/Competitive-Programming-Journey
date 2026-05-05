#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            mx = max(mx,a[i]);
        }
        int i = 0;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(a[j]==mx){
                
                i=j+1;
            }else{
                cnt += (j-i+1);
            }
        }
        cout<<cnt<<endl;



    }
    
    
    return 0;
}