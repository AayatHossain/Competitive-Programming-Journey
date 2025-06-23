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
int dp[S][N];

int f(int w, int i)
{
    if (i == n)
        return 0;
    if(dp[w][i]!=-1)return dp[w][i];
    if (w <= a[i].s)
    {
        int v1 = a[i].v + f(w + a[i].w, i + 1);
        int v2 = f(w, i + 1);
        return dp[w][i] = max(v1, v2);
    }
    else
    {
        int v2 = f(w, i + 1);
        return dp[w][i] = v2;
    }
}

signed main()
{
    cin >> n;
    a.resize(n);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].w = x;
        a[i].s = y;
        a[i].v = z;
    }

    // for(int i = 0; i < n; i++){
    //     cout<<a[i].w<<" "<<a[i].s<<" "<<a[i].v<<endl;
    // }
    sort(a.begin(), a.end(), [](const node1 &i, const node1 &j)
         { return i.w + i.s < j.w + j.s; });

    int ans = f(0, 0);
    cout << ans << endl;

    return 0;
}