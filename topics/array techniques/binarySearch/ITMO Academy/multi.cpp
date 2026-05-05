#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(int mid, int k, vector<vector<int>> &a)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int left = a[i][0];
        int right = a[i][1];
        int temp;
        if (mid > left)
        {
            if (mid > right)
            {
                temp = right - left + 1;
            }
            else
            {
                temp = mid - left;
            }

           int temp2 = i+1;
           int val = (temp+temp2-1)/temp2;

            if (i != 0)
            {
                count += val;
            }
            else
            {
                count += temp;
            }
            // if(mid==10){
            //     cout<<count<<" ";
            // }
            // cout<<endl;
        }
    }
    // cout << mid << ": " << count << endl;
    return count <= k;
}
signed main()
{
    int n, k;
    cin >> n >> k;
    k--;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        a[i][0] = i + 1;
        a[i][1] = (i + 1) * n;
    }
    int l = 1, r = 1e11;
    int mid;
    while (r > l + 1)
    {
        mid = l + (r - l) / 2;

        if (ok(mid, k, a))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << endl;
}