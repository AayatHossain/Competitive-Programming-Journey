#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
vector<bool> p(N+1, 1);
signed main()
{
    p[0] = false;
    p[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (p[i])
        {
            for (int j = i + i; j <= N; j += i)
            {
                p[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    int tc = 1;

    while (t--)
    {
        int n;
        cin >> n;
        int ans = 1;
        set<int> s;
        for(int i = 2; i*i <= n; i++){
            if(n%i==0){
                // cout<<i<<endl;
                // ans = ans*i;
                
                // int n1 = n/i;
                int n1 = i;
                int n2 = n/i;
                cout<<n1<<" "<<n2<<endl;
                if(p[n1])s.insert(n1);
                if(p[n2])s.insert(n2);
                
            }
        }
        for(auto x: s){
            ans *= x;
        }
        cout<<ans<<endl;
    }
    return 0;
}