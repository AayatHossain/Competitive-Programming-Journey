#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
map<string, int> dp;

int f(string s, string w, int i, string temp){
   if(temp.size()==w.size()){
        if(temp==w){
            return 1;
        }else{
            return 0;
        }
    }
    if(i==s.size() || temp.size() > w.size()){
        return 0;
    }
    if(dp.find(temp) != dp.end()){
        return dp[temp];
    }
    return dp[temp] =  (f(s,w,i+1,temp+s[i])%mod + f(s,w,i+1,temp)%mod)%mod;
}
signed main(){
    string s,w;cin>>s>>w;
    int ans = f(s,w,0,"");
    cout<<ans%mod<<endl;
    return 0;
}