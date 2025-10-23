#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++)
    {
        v[i] = (a * v[i - 1] + b) % c;
    }
    // for(auto z: v){
    //     cout<<z<<" ";
    // }
    // cout<<endl;
    deque<int> dq;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            while(!dq.empty() && v[dq.back()] >= v[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i==k-1){
                ans^=v[dq.front()];
            }
        }
        else
        {

            if(dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && v[dq.back()] >= v[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            ans^=v[dq.front()]; 
        }

        // if(i>=k-1){
        //     cout<<v[dq.front()]<<endl;
        // }
    }
    cout<<ans<<endl;

    return 0;
}