#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,t;cin>>n>>t;
    string s;cin>>s;
    int m = s.size();
    while(t > 0){
        for(int i = 0; i < n-1; i++){
            if(s[i]=='B' && s[i+1]=='G'){
                s[i] = 'G'; s[i+1] = 'B';
                i++;
            }
        }
        t--;
    }
    cout<<s<<endl;
    
    return 0;
}