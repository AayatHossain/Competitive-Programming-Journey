#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (auto x : a)
    {
        for (int i = s; i >= 1; i--)
        {
            
            if(i-x >= 0){
                dp[i] = dp[i - x] | dp[i];
            }
            
        }
    }
    
    int c=0;
    for(int i = 1; i<=s; i++){
        if(dp[i])c++;
    }
    cout<<c<<endl;
    for(int i = 1; i <=s; i++){
        if(dp[i])cout<<i<<" ";
    }
    cout<<'\n';
   

    return 0;
}