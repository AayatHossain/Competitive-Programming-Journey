#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;
        cin>>s;
        int flag = 0;
        
            int o = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i]=='1'){
                    o++;
                }
            }
            if(o <=1 ){
                flag = 1;
            }else{
                int left = o - k;
                if(left == 0){
                    flag = 1;
                }
                if(k > n/2 && o%k != 0){
                    flag = 1;
                }
            }
        
        if(flag){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }

    }
    return 0;
}