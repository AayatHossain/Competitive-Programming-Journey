#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        int f=0;
        int cl = 0,cr = 0;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i < n-1 && s[i]=='*' && s[i+1]=='*'){
                f=1;
                break;
            }
            if(i < n-1 && s[i]=='>' && s[i+1]=='<'){
                f = 1;
                break;
            }

            if(i < n-1 && s[i]=='>' && s[i+1]=='*'){
                f = 1;
                break;
            }

            if(i < n-1 && s[i]=='*' && s[i+1]=='<'){
                f = 1;
                break;
            }
            
            if(s[i]=='>' || s[i]=='*'){
                cr++;
                mx = max(mx,cr);
            }else{
                cr=0;
            }

            if(s[i]=='<' || s[i]=='*'){
                cl++;
                mx = max(mx,cl);
            }else{
                cl=0;
            }
        }
        mx = max(mx,cr);
        mx = max(mx,cl);
        if(f)mx=-1;
        cout<<mx<<endl;

    }
    return 0;
}