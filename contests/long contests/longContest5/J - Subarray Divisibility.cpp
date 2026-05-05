#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> p(n);
    p[0] = a[0];
    for(int i = 1; i< n; i++){
        p[i] = p[i-1] + a[i];
    }
    map<int,int> m;
    m[0] = 1;
    int count = 0;
    for(int i = 0; i < n; i++){
        int mod = p[i]%n;
        if(mod < 0){
            mod += n;
        }
        count += m[mod];
        m[mod]++;
        
    }
    cout<<count<<endl;
    return 0;
}