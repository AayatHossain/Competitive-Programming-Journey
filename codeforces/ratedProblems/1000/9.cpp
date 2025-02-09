#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        auto it = unique(a.begin(), a.end());

        
        a.erase(it, a.end());
        // for(int i = 0; i < a.size(); i++){
        //     cout<<a[i]<<" ";
        // }
        if (a[0] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {

            int flag = 1;
            int x = a[0];
            int y = a[1];
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] % x == 0 || a[i] % y == 0)
                {
                    // cout<<"HI"<<endl;
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                 flag = 0;
                int x = a[0];

                int part2 = -1;
                for (int i = 0; i < a.size(); i++)
                {
                    if (a[i] % x == 0)
                    {
                        part2 = i;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if (part2 == n - 1)
                {
                    cout << "YES" << endl;
                    flag = 1;
                }
                else
                {
                    int part3 = -1;
                    int y = a[part2 + 1];
                    for (int i = part2 + 1; i < a.size(); i++)
                    {
                        if (a[i] % y == 0)
                        {
                            part3 = i;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (part3 == n - 1)
                    {
                        cout << "YES" << endl;
                        flag = 1;
                    }
                }
                if (!flag)
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}