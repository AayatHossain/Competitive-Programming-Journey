#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 1;
struct node1
{
    int w, s, v;
};
vector<node1> a;
int n;
const int S = 1e5+1;

signed main()
{
    cin >> n;
    a.resize(n);
    int totalWeight = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].w = x;
        a[i].s = y;
        a[i].v = z;
        totalWeight+=x;
    }

    // for(int i = 0; i < n; i++){
    //     cout<<a[i].w<<" "<<a[i].s<<" "<<a[i].v<<endl;
    // }
    sort(a.begin(), a.end(), [](const node1 &i, const node1 &j)
         { return i.w + i.s < j.w + j.s; });

    int dp[n+1][totalWeight+1];
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <= totalWeight; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            if(j <= a[i].s && j-a[i].w){
                int v1 = a[i].v + dp[i-1][j-a[i].w];
                int v2 = dp[i-1][j];
                dp[i][j] = max(v1,v2);
            }else{
                int v2 = dp[i-1][j];
                dp[i][j] = v2;
            }
        }
    }
    cout<<dp[n][totalWeight]<<endl;


    return 0;
}