#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;vector<int>a(n);vector<int>p(n);
        cin>>a[0];p[0]=a[0];
        for(int i = 1; i < n; i++){
            cin>>a[i];p[i]=p[i-1]+a[i];
        }
        int mx = LLONG_MIN/2;
        int sum = 0;
        for(int i = n-1; i >=1; i--){
            sum += a[i];
            int index = lower_bound(p.begin(), p.end() - (n-i+1), sum) - p.begin();
            if(index != n && p[index]==sum){
                mx = max(mx, (n-i)+index+1);
            } 
        }
        if(mx==LLONG_MIN/2){
            mx = 0;
        }
        cout<<mx<<endl;
    }
}