#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int zeros = 0;
        int ones = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='0'){
                zeros++;
            }else{
                ones++;
            }
        }
        if(zeros==ones){
            cout<<0<<endl;
            continue;
        }
        
        int index = -1;
        for(int i = 0; i < s.size();i++){
            if(s[i]=='0'){
                ones--;
            }else{
                zeros--;
                
            }
            if(ones < 0 || zeros<0){
                index = i;
                break;
            }
            
        }
        if(index==-1){
            cout<<0<<endl;
        }else{
            cout<<s.size()-(index)<<endl;
        }
        // cout<<s.size()-balanced<<endl;
    }
    return 0;
}