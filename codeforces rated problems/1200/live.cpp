#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        int same = 1;
        for(int i = 0; i < n-1; i++){
            if(a[i] != a[i+1]){
                same = 0;
                break;
            }
        }
        int mv = b[n-1];
        // cout<<mv<<endl;
        if(same){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            int flag = 0;
            for(int i = 0; i < n; i++){
                if(!flag && a[i]==mv){
                    cout<<2<<" ";
                    flag = 1;
                }else{
                    cout<<1<<" ";
                }
            }
            cout<<endl;
        }
    }
}