#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n ;i++){
            cin>>a[i];
        }
        int d = INT_MIN;
        map<int,int> m;
        for(int i = 0; i < n; i++){
            if(m.find(a[i]) != m.end()){
                int curr = i+1;
                int prev = m[a[i]];
                int v = prev + (n-curr);
                // cout<<curr<<" "<<prev<<endl;
                d = max(d, v);
            }
            m[a[i]] = i+1;
            // cout<<a[i]<<" "<<m[a[i]]<<endl;
        }   
        if(d==INT_MIN){
            cout<<-1<<endl;
        }else{
            cout<<d<<endl;
        }
    }
    return 0;
}