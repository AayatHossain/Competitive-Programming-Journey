#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int d=0,k=0;
        for(int i = 0; i < n; i++){
            if(s[i]=='D')d++;
            if(s[i]=='K')k++;
            cout<<gcd(d,k)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}