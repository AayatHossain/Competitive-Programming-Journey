#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        vector<int> p(n+1,0);
        for(int i = 1; i <= n; i++){
            if(s[i-1]=='a'){
                p[i] = p[i-1] + 1;
            }else{
                p[i] = p[i-1] - 1;
            }
        }

        // for(auto x: p){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int sum = p[n];

        map<int,int> m;
        m[0] = 0;
        int mn = INT_MAX;
        for(int i = 1; i <= n; i++){
            int left = p[i] - sum;
            if(m.find(left) != m.end()){
                mn = min(mn, i - m[left]);
                // cout<<i<<endl;
            }
            m[p[i]] = i;
        }
        if(mn==INT_MAX || mn==s.size())mn = -1; 
        if(sum==0)mn=0;
        
        cout<<mn<<endl;

    }
    return 0;
}