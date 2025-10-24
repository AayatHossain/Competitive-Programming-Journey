#include<bits/stdc++.h>
using namespace std;
signed main(){
    string s; cin>>s;
    int n = s.size();


    for(int i = 1; i < n; i++){
            
            char l = s[i-1];
            char r;
            if(i+1 < n){
                r = s[i+1];
            } else{
                r = '.';
            }
            // if(i==3){
            //     cout<<l<<" "<<r<<endl;
            // }
            if(s[i]==l && s[i]==r){
                for(int j = 0; j < 26; j++){
                    char c = 'a'+j;
                    // cout<<c<<endl;
                    if(c!=l && c!=r){
                        s[i]=c;
                        break;
                    }
                }
            }
            
        
        // cout<<s<<endl;
    }



    for(int i = 1; i < n; i+=2){
            
            char l = s[i-1];
            char r;
            if(i+1 < n){
                r = s[i+1];
            } else{
                r = '.';
            }
            // if(i==3){
            //     cout<<l<<" "<<r<<endl;
            // }
            if(s[i]==l || s[i]==r){
                for(int j = 0; j < 26; j++){
                    char c = 'a'+j;
                    // cout<<c<<endl;
                    if(c!=l && c!=r){
                        s[i]=c;
                        break;
                    }
                }
            }
            
        
        // cout<<s<<endl;
    }
    cout<<s<<endl;
    // char c = 'a'+25;
    // cout<<c<<endl;
    return 0;
}   