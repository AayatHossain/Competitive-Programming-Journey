#include<bits/stdc++.h>
using namespace std;
signed main(){
    string s;cin>>s;
    int m;cin>>m;
    int c = 0;
    int p1 = -1, p2 = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='1'){
            c++;
            p1 = p2;
            p2 = i;
        }
    }
    if(c>1){
        p1++;p2++;
        cout<<"YES"<<endl;
        while(m>0){
            cout<<p1<<" ";
            m--;
            if(m==0){
                break;
            }
            cout<<p2<<" ";
            m--;
        }
    }else{
        cout<<"NO"<<endl;
    }
    cout<<endl;
    return 0;
}