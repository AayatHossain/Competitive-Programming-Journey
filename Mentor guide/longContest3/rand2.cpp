#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        if(n<=3){
            cout<<"NO"<<endl;
        }else{
            set<string> st;
            string s1;
            s1+=s[0];
            s1+=s[1];
            string s2;
            s2+=s[1];
            s2+=s[2];
            st.insert(s1);
            st.insert(s2);
            int found = 0;
            int j = 1;
            if(j + 2 < n && s[j]==s[j+2]){
                j = j+2;
            }
            
            for(int i = j; i < n - 1; i++){
                string s3;
                s3+=s[i];
                s3+=s[i+1];
                if(st.find(s3) != st.end()){
                    found = 1;
                    break;
                }else{
                    st.insert(s3);
                    if(i+2 < n && s[i]==s[i+2]){
                        i = i+1;
                    }
                }
               
            }
            if(found){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }

        }
        
    }
    return 0;
}