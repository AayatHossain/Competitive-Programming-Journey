#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        int c = 0,p=0;
        int m = 1;
        vector<int> res(n+1);
        for(int i = 1; i <= n; i++){
            c = a[i];
            int d = c-p;
            int indx = i - d;
            if(indx<=0){
                res[i]=m;
                m++;
            }else{
                res[i] = res[indx];
            }
            p = c;
        }
        for(int i = 1; i <= n; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}