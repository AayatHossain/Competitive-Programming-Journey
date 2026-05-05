#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;cin>>n;string s;cin>>s;
    int count = 0;
    for(int i = n-1; i >= 0; i--){
        int n = s[i] - '0';
        if((n&1)==0){
            count += i+1;
        }
    }
    cout<<count<<endl;
    return 0;
}