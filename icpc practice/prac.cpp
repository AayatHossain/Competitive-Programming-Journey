#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int c = 0;
        char line[s.size()];

        for(int i = 0; i < s.size(); i++){
            line[i] = s[i];
        }


        for(int i = 0; i < s.size(); i++){
            if(s[i]=='0'){
                c--;
                break;
            }
            c++;
        }
        // cout<<sizeof(line)<<endl;
        cout<<sizeof(line)<<" "<<c<<endl;  
    }
    return 0;
}

