#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        string s;cin>>s;
        int c1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='1'){c1++;}
        }
        int ans = -1;
        if(c1==0){
            ans=0;
        }
        if((c1&1)==0 && c1 > 2){
            ans = c1/2;
        }
        if(c1==2){
            int pos1=-1;
            for(int i = 0; i < n; i++){
                if(s[i]=='1'){
                    pos1 = i;
                    break;
                }
            }
            int pos2 = -1;
            for(int i = pos1+1; i < n; i++){
                if(s[i] == '1'){
                    pos2 = i;
                    break;
                }
            }
            if(pos2 - pos1 >1){
                ans = 1;
            }else{
                if(n==3){
                    ans = -1;
                }
                else if(n==4 && pos1==1){
                    ans = 3;
                }else{
                    ans = 2;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}