#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        int c1 = 0, c0 = 0;
        for(int i  =0;i < n; i++){
            cin>>a[i];
            if(a[i]==1){
                c1++;
            }else{
                c0++;
            }
        }
        int consecutiveZero = 0;
        for(int i = 1; i < n; i++){
            if(a[i]==a[i-1] && a[i] == 0){
                consecutiveZero = 1;
                break;
            }
        }
        if(c1==n || c0 == n){
            cout<<"YES"<<endl;
        }else if(consecutiveZero == 1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}