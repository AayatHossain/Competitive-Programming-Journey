#include<bits/stdc++.h>
using namespace std;
signed main(){
   string s;cin>>s;
   stack<char> st;
   int moves = 0;
   for(int i = 0; i < s.size();i++){
        if(st.empty() || st.top()!=s[i]){
            st.push(s[i]);
        }else{
            moves++;
            st.pop();
        }
   }
   if(moves & 1){cout<<"Yes"<<endl;}
   else{cout<<"No"<<endl;}
    return 0;
}