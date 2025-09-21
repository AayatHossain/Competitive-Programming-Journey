#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int n;
 int vis[N][2];

bool diff(int a, int b)
{
    if ((a & 1) && (!(b & 1)))
    {
        return true;
    }
    else if ((b & 1) && (!(a & 1)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct node
{
    int v, i, m, oi;
};
queue<node> q;

void bfs(vector<int> &a, vector<int> &res)
{
    while (!q.empty())
    {
        node no = q.front();
        q.pop();
        int uv = no.v;
        int ui = no.i;
        int um = no.m;
        int uoi = no.oi;
        int prev = 0;
        if(um&1){
            prev = 1;
        }

        if (res[uoi] != -1)
            continue;
        

        int v1 = ui + uv;
        int v2 = ui - uv;

        if (v1 >= 1 && v1 <= n)
        {
            if(vis[prev][v1] != -1){
                res[uoi]= um+vis[prev][v1];
            }
            else if (diff(uv, a[v1]))
            {
                vis[prev][v1] = um+1;
                res[uoi] = um + 1;
            }
            else
            {
                vis[prev][v1] = um+1;
                q.push({a[v1], v1, um + 1, uoi});
            }
        }
        if (v2 >= 1 && v2 <= n)
        {
            if(vis[prev][v2] != -1){
                res[uoi]= um+vis[prev][v2];
            }
            else if (diff(uv, a[v2]))
            {
                vis[prev][v2] = um+1;
                res[uoi] = um + 1;
            }
            else
            {
                vis[prev][v2] = um+1;
                q.push({a[v2], v2, um + 1, uoi});
            }
        }
        if ((v1 < 1 || v1 > n) && (v2 < 1 || v2 > n))
        {
            res[uoi] = -1;
        }
    }
}

signed main()
{
    cin >> n;

    vector<int> a(n+1);
    vector<int> res(n+1, -1);
   
    memset(vis, -1, sizeof vis);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q.push({a[i], i, 0, i});
    }
    bfs(a,res);
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}