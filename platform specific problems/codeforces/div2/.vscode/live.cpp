#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int i = 0; int j = i+1; int c = 0;
        while(j < n){
            if(a[j] > a[i] + 1){
                c++; i = j; j= i+1;
            }else{
                j++;
            }
        }
        cout<<c+1<<endl;
    }
    return 0;
}