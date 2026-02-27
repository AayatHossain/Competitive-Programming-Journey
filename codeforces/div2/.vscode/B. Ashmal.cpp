#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string ans = "";
        int l = 0;
        int m;
        for(int i = 0; i < n; i++){
            string s; cin>>s;
            m = s.size();
            int p = 0,q=0;
            int f = -1;
            while(p < m && q < l){
                if(s[p] == ans[q]){
                    p++;q++;
                }else if(s[p] < ans[q]){
                    f=1;
                    break;
                }else{
                    f = 0;
                    break;
                }
            }
            // cout<<f<<s<<endl;
            
            if(f==-1 && m <= l){
                string temp = s;
                s+=ans;
                ans = s;
            }else if(f==-1 && m > l){
                ans+=s;
            }
            else if(f==1){
                string temp = s;
                s+=ans;
                ans = s;
                
               
            }else{
                ans+=s;
            }
             l+=m;
            //  cout<<l<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}