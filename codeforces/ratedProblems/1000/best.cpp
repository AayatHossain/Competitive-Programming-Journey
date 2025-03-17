#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;string ans;
        char curr = 'a';
        for(int i = 0; i < s.size(); i++){
            char val = s[i];
            if(val == '?'){
                if(curr == 'a'){
                    ans+= '0'; curr = '0';
                }else{
                    ans += curr;
                }
            }else{
                ans += val; curr = val;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}