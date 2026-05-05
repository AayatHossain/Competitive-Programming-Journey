#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];
        vector<int>p(n); p[0] = a[0]; for(int i=1;i<n;i++)p[i]=p[i-1]+a[i];
        int ans=LLONG_MIN;
        for(int k=1;k<=n/2;k++){
            int M=LLONG_MIN;
            int m=LLONG_MAX;
            if(n%k==0){
                M = max(M,p[k-1]);
                m = min(m, p[k-1]);
                for(int i=(k+k)-1; i<n; i+=k){
                    int s = p[i]-p[i-k];
                    M = max(M,s);
                    m = min(m, s);
                }
                ans = max(ans, abs(M-m));
            }
        }
        ans = max(ans, 0LL);
        cout<<ans<<endl;


        
    }
    return 0;
}