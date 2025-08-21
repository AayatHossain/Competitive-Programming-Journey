#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;cin>>n;
        vector<int>a(n);
        int o=0,e=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]&1)o++;
            else e++;
        }
        sort(a.begin(),a.end());
        int f=0;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1)f=1;
        }
        int g=0;
        if(o%2==0 && e%2==0){
            g=1;
        }else if(f){
            g=1;
        }
        if(g)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}