#include<bits/stdc++.h>
using namespace std;
bool valid(string s){
    if(s.size()==0){
        return true;
    }
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='('){
            st.push('(');
        }else{
            if(st.empty()){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s; cin>>s;
        string newstring = s.substr(1, s.size() - 2);
        // cout<<newstring<<endl;
        bool isValid = valid(newstring);
        if(isValid){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}