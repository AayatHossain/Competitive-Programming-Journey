#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < n; i++){
            if(st.size() > 0 && st.top()=='A' && s[i]=='B'){
                st.pop();
            }
            else if(st.size() > 0 && st.top()=='B' && s[i]=='B'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        cout<<st.size()<<endl;
    }
    return 0;
}