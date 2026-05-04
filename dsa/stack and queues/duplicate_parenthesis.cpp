//n and n complexity
//using stack and pair of previous pop, where the distance of previous pop and current pop of both first second brackets should be 1
#include <bits/stdc++.h> 
bool duplicateParanthesis(string &s)
{
    int n = s.size();
    stack<int> st;
    pair<int,int> p = {-1,-1};
    for(int i = 0; i < n; i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i] == ')' && !st.empty()){
            if(st.top()==p.first-1
                && i==p.second+1){
                return true;
            }else{
                p = {st.top(),i};
            }
            st.pop();
        }else if(s[i]==')'){
            return false;
        }
    }
    return false;
}
