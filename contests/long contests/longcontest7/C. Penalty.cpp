#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int l1 = 5, l2 = 5;
        int ans = -1;
        for(int i = 0; i < 9; i++){
            if(i&1){
                l2--;
            }else{
                l1--;
            }
            //1s favor
            int p1b = 0;
            int p2b = 0;
            for(int j = 0; j <= i; j++){
                if(s[j]=='1' && j&1){
                    p2b++;
                }
                if(s[j]=='1' && !(j&1)){
                    p1b++;
                }
                if(s[j]=='?' && !(j&1)){
                    p1b++;
                }
            }
            // if(i==4){
            //     cout<<l1<<" "<<l2<<endl;
            //     cout<<p1b<<" "<<p2b<<endl;
            // }
            if(p1b + l1 < p2b){
                ans = i;
                break;
            }
            if(p2b + l2 < p1b){
                ans = i;
                break;
            }
            //2s favor
             p1b = 0;
             p2b = 0;
            for(int j = 0; j <= i; j++){
                if(s[j]=='1' && j&1){
                    p2b++;
                }
                if(s[j]=='1' && !(j&1)){
                    p1b++;
                }
                if(s[j]=='?' && (j&1)){
                    p2b++;
                }
            }
            // if(i==4){
            //     // cout<<l1<<" "<<l2<<endl;
            //     cout<<p1b<<" "<<p2b<<endl;
            // }

            if(p1b + l1 < p2b){
                ans = i;
                break;
            }
            if(p2b + l2 < p1b){
                ans = i;
                break;
            }
        }
        if(ans==-1){
            ans = 9;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}