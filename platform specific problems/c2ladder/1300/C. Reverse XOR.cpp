#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n;  cin>>n;
        string s;
        int f = 0;
        for(int i = 31; i >= 0; i--){
            int mask = (n&(1<<i));
            if(mask && !f){
                s+='1';
                f=1;
            }else if(f){
                if(mask)s+='1';
                else s+='0';
            }
        }
        int m = s.size();
        int index = -1;
        for(int i = m-1; i>=0; i--){
            if(s[i]=='1'){
                index = i;
                break;
            }
        }
        int i = 0, j = index;

        // cout<<s<<endl;
        // cout<<j<<endl;

        f = 1;
        if(i==j)f=0;
        while(i <= j && f){
            if(i==j && s[i]=='1'){
                f=0;
                break;
            }
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                f = 0;
                break;
            }
        }
        
        if(f){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}