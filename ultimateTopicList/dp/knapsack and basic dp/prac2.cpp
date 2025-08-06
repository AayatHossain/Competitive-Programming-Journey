#include <bits/stdc++.h>
using namespace std;
#define int long long

int f1(int l, int r)
{
    int ans;
    int n = r - l + 1;
    if (l == r)
    {
        ans = l * 2;
    }
    else
    {
        ans = (n - 2) + __gcd(l, r) + r;
    }
    return ans;
}

int f2(int l, int r)
{
    vector<int> a;
    for (int i = l; i <= r; i++)
    {
        a.push_back(i);
       
    }
    if(l==r){
        a.push_back(l);
        
    }

    
    int n = a.size();
    int m;

    int s = 0;
    while (n != 0)
    {
        // for(int i = 0; i < n; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;

        int g = 0;
        for (int i = 0; i < n; i++)
        {
            g = gcd(g, a[i]);
        }
        s += g;
        // cout<<"askjdhasjd"<<s<<endl;

        m = n / 2;
        if (n % 2 == 0)
            m--;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (i != m)
            {
                temp.push_back(a[i]);
            }
        }
        n--;
        a.clear();
        a = temp;
        
    }
    return s;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1e8; i <= 1e8; i++)
        {
            for (int j = i; j <= 1e8+200; j++)
            {
                int ans3 = f1(i, j);
                int ans4 = f2(i, j);
                if (ans3 != ans4)
                {
                    cout << "Wrong" << " " << i << " " << j << endl;
                    cout<<ans3<<" "<<ans4<<endl;
                    break;
                }
            }
        }
        // int ans = f2(1,1);
        
        cout<<"CP"<<endl;
    }
    return 0;
}