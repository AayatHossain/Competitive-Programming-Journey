#include<bits/stdc++.h>
using namespace std;
signed main(){
    string s;cin>>s;
    for(int i = 1; i < s.size()-1; i++){
        if(s[i]==s[i-1]){
            for(int j = 97; j <= 122; j++){
                char c = j;
                if(c != s[i-1] && c != s[i+1]){
                // cout<<c<<endl;
                s[i] = c;
                    break;
                }
            }
        }
    }
    if(s[s.size()-1] == s[s.size() - 2]){
        for(int j = 97; j <= 122; j++){
            char c = j;
            if(c != s[s.size()-2]){
            // cout<<c<<endl;
            s[s.size()-1] = c;
                break;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}