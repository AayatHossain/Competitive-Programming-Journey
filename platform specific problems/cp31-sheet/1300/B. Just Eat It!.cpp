#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        int s = 0;
        int c = 0;
        int mx1 = LLONG_MIN;
      
        for(int i = 0; i < n; i++){
            cin>>a[i];
            s+=a[i];
        }

        for(int i = 1; i < n; i++){
            c+=a[i];
            if(c < 0){
                c = 0;
            }
            mx1 = max(mx1, c);
        }
        c=0;
        for(int i = 0; i < n-1; i++){
            c+=a[i];
            if(c < 0){
                c = 0;
            }
            mx1 = max(mx1, c);
        }
        // cout<<mx1<<" "<<mx2<<endl;
       if(mx1 >= s){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}