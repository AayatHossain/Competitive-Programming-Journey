#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t))return 0;
    while(t--){
        int n; string s;
        cin>>n>>s;
       
        for(char c:s){ if(c=='p') hasP=true; if(c=='s') hasS=true; }
        if(!hasP || !hasS){ cout<<"YES\n"; continue; }
        bool pBeforeS=false;
        for(int i=0;i<n;i++) if(s[i]=='p') for(int j=i+1;j<n;j++) if(s[j]=='s') pBeforeS=true;
        if(pBeforeS){ cout<<"NO\n"; continue; }
        bool pattern=false;
        for(int i=0;i<n;i++) if(s[i]=='.') for(int j=i+1;j<n;j++) if(s[j]=='s') for(int k=j+1;k<n;k++) if(s[k]=='p') for(int l=k+1;l<n;l++) if(s[l]=='.') pattern=true;
        if(pattern){ cout<<"NO\n"; continue; }
        cout<<"YES\n";
    }
    return 0;
}
