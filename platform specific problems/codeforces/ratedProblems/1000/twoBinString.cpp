#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        string s,t;cin>>s>>t;
        int n = s.size();
        int flag = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i]==t[i]){
                if(s[i]=='0'){
                    if(s[i+1]==t[i+1]){
                        if(s[i+1]=='1'){
                            flag = 1;
                        }
                    }
                }
            }
        }
        cout<<(flag? "YES" : "NO")<<endl;
    }
    return 0;
}