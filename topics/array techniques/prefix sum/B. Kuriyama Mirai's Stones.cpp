#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());

    for(int i = 2; i <= n; i++){
        a[i] = a[i-1] + a[i];
        b[i] = b[i-1] + b[i];
    }

   

    int m; cin>>m;
    for(int i = 0 ;i < m; i++){
        int t,l,r; cin>>t>>l>>r;
        if(t==1){
            cout<<a[r]-a[l-1]<<endl;
        }else{
            cout<<b[r]-b[l-1]<<endl;
        }
    }

    return 0;
}