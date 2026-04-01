#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        for(int i = 0 ;i < n; i++){
            int v = s[i] - '0';
            int j = 0;
            int index = -1;
            // cout<<v<<endl;
            while(i + j < n && j < 10){
                int val = s[i+j]-'0' - (j);
                // if(i==3){
                //         cout<<val<<endl;
                //     }
                if(val > v){
                    
                    index = j+i;
                    v = val;
                 
                }
                j++;
            }
            for(int k= index; k > i && index != -1; k--){
                swap(s[k-1],s[k]);
                s[k-1]--;
            }
        }
        cout<<s<<endl;
    }  

    return 0;
}