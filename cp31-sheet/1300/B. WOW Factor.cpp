#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string s; cin>>s;
    int n = s.size();
    vector<int> p(n,0);
    vector<int> su(n,0);
    int c = 0;
    int total = 0;
    for(int i = 1; i < n; i++){
        if(s[i]=='v' && s[i-1]=='v'){
            c++;
        }else{
            total+=c;
            p[i] = total;
            c = 0;
        }
    }
    total = 0;
    c=0;
    for(int i = n-2; i >= 0; i--){
        if(s[i]=='v' && s[i+1]=='v'){
            c++;
        }else{
            total+=c;
            su[i] = total;
            c = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i > 0 && i < n-1 && s[i]=='o' ){
            ans += p[i]*su[i];
        }
    }
    // for(auto x: p){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x: su){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    cout<<ans<<endl;

    return 0;
}