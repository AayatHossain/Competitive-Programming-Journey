
// https://codeforces.com/problemset/problem/2039/B

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        int flag= 0;
        if(a.size()==2){
            if(a[0]==a[1]){
                cout<<a<<endl;
                continue;
            }
        }
        for(int i = 0; i < int(a.size() - 2); i++){
        

            if(a[i] != a[i+1] && a[i+1]!= a[i+2] && a[i] != a[i+2]){
                cout<<a[i]<<a[i+1]<<a[i+2]<<endl;
                flag = 1;
                break;
            }
            if(a[i]==a[i+1]){
                cout<<a[i]<<a[i+1]<<endl;
                flag = 1;
                break;
            }
            if(a[i+1]==a[i+2]){
                cout<<a[i+1]<<a[i+2]<<endl;
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
        }
    }
    return 0;
}