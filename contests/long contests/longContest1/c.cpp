#include<bits/stdc++.h>
using namespace std;
signed main(){
    string s; cin>>s;
    int i = 0; int j = s.length() - 1;
    int count = 0;a
    while(i < j){
        if(s[i] != s[j]){
            count++;
        }
        i++; j--;
    }
    cout<<count<<endl;
    return 0;
}