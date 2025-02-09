// https://codeforces.com/problemset/problem/1941/B
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int flag = 1;
        for(int i = 0; i < n-2; i++){
            if(a[i] == 0){
                continue;
            }
            if(a[i] < 0){
                flag = 0;
                break;
            }else{
                int count = a[i];
                a[i] -= count;
                a[i+1] -= (count*2);
                a[i+2] -= count;
            }
        }
        if(a[n-1] != 0 || a[n-2] != 0){
            flag = 0;
        }
        // for(int i = 0; i < n; i++){
        //     cout<<a[i]<<" ";
        // }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;

        }
    }
        
    return 0;
}