#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        vector<int> seg;
        int c = 1;
        int n = s.size();
        for(int i= 1; i < s.size(); i++){
            if(s[i]==s[i-1]){
                c++;
            }else{
                seg.push_back(c);
                c=1;
            }
        }   
        seg.push_back(c);
        // for(auto x: seg){
        //     cout<<x<<" ";
        // }
        int ans1 = n - seg.size();
        int ans2 = 1;
        for(int i = 0; i < seg.size(); i++){
            ans2 = (ans2*seg[i])%998244353;
        }
        int v = (n-seg.size());
        for(int i = 2; i <= v; i++){
            ans2 = (ans2*i)%998244353;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}