#include<bits/stdc++.h>
using namespace std;
#define int long long 

int calc(string t, int n){
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(t[i]==t[i-1])continue;
        else cnt++;
    }
    return cnt;
}

signed main(){
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int mx = INT_MIN;
        for(int j = n; j >= 1; j--){
            string t;
            for(int k = j; k < n; k++){
                t+=s[k];
            }
            for(int i = 0; i < j; i++){
                t+=s[i];
            }
            mx = max(mx, calc(t,n));
            // cout<<t<<endl;
        }
        cout<<mx<<endl;
    }
   
    return 0;
}