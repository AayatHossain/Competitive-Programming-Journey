#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        for(int i = 0; i < n; i++)cin>>b[i];
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(a[i] >= b[i]){
                sum+=a[i];
                c.push_back(b[i]);
            }else{
                sum+=b[i];
                c.push_back(a[i]);
            }
        }
        sort(c.begin(),c.end());
        int cnt = 0;
        for(int i = c.size()-1; i>=0; i--){
            if(cnt==k-1)break;
            sum+=c[i];
            cnt++;
        }
        cout<<sum+1<<endl;
    }
    return 0;
}