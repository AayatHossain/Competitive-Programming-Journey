#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;cin>>n;vector<int>a(n);
    for(int i = 0;i < n; i++)cin>>a[i];
    vector<int> count(n);
    for(int i = 0; i < n; i++){
        int steps = 0;
        if((i&1)==1){
            if(i > a[i]){
                steps = a[i] + (n - i );
            }else{
                steps = a[i] - i;
            }
        }else{
            if(i < a[i]){
                steps = i + n - a[i];
            }else{
                steps = i - a[i];
            }
            
        }
        count[i] = steps;
    }
    bool flag = 1;
    for(int i = 1; i < n; i++){
        if(count[i] != count[i-1]){
            flag = 0;
            break;
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout<<count[i]<<" ";
    // }

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

    }
}