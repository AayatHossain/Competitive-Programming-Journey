#include<bits/stdc++.h>
using namespace std;
signed main(){
    string s;cin>>s;
    string ns;
    int n = s.size();
    ns+=s[0];
    if(n ==1){
        cout<<ns<<endl;
        return 0;
    }
    ns+=s[1];
    for(int i = 2; i < n; i++){
        int m = ns.size();
        if(s[i]==ns[m-1] && s[i]==ns[m-2]){
            continue;
        }else if(m >= 3 && s[i]==ns[m-1] && ns[m-2]==ns[m-3]){
            continue;
        }else{
            ns+=s[i];
        }
        // cout<<ns<<endl;
    }
    cout<<ns<<endl;
    // for(int i = 0; i < n; i++){
    //     int j = i;
    //     int c = 0;
    //     while(j < n && s[i]==s[j]){
    //         j++;c++;
    //     }
    //     i = j-1;
    //     if(c>=2){
    //         ns+=s[i];
    //         ns+=s[i];
    //     }else{
    //         ns+=s[i];
    //     }
    // }
    // string fs;
    // for(int i = 0; i < ns.size(); i++){
    //     if(i+3 < ns.size() && ns[i]==ns[i+1] && ns[i+2]==ns[i+3]){
    //         fs+=ns[i];
    //         fs+=ns[i];
    //         fs+=ns[i+2];
    //         i = i+3;
    //     }else{
    //         fs+=ns[i];
            
    //     }
        
    // }
    // cout<<ns<<endl;
    // cout<<fs<<endl;
    return 0;
}