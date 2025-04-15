#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string s; 
    getline(cin, s);
    // cout<<s<<endl;

    stack<int> st;
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        // cout<<c<<endl;
        if(c == ' '){
            continue;
        }else if(c =='+' || c=='-' || c=='*'){
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            int val;
            if (c=='+'){
                val = v1 + v2; 
            }
            if (c=='-'){
                val = v2 - v1; 
            }
            if (c=='*'){
                val = v1 * v2; 
            }
            // cout<<val<<endl;
            st.push(val);
        }else{
            string temp;
            int j = i;
            while(j < s.size() && s[j] != ' ' && (s[j] != '+' || s[j] != '-' || s[j] != '*' )){
                temp += s[j]; j++;
            }
            i = j-1;
            int val = stoi(temp);
            // cout<<val<<endl;
            st.push(val);
        }
    }
    cout<<st.top()<<endl;
    
}