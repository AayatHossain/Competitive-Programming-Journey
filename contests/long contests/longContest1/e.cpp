#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;cin>>n;string s;cin>>s;
    int z = 0, o = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='0'){
            z++;
        }else{
            o++;
        }
    }
    int mV = min(o, z);
    int remove = mV*2;
    cout<<n-remove<<endl;
    return 0;
}