#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,x; cin>>n>>x;
    vector<int> a(n+1,0);
    for(int i = 1; i <= n; i++)cin>>a[i];
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] + a[i];
    }
    map<int,int> m;
    // s.insert(0);
    int c = 0;
    for(int i = 1; i <= n; i++){
        int v = a[i] - x;
        if(v==0){
            c++;
        }
        if(m[v]>0){
            c+=m[v];
        }
        m[a[i]]++;
    }
    cout<<c<<endl;
    return 0;
}