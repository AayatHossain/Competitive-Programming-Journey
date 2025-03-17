#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k;
        string s;
        cin >> n >> x >> k >> s;
        int ans = 0;
        int time = k;
        int position = x;

        int zeroFound = -1;
        int currIndex = -1;
        for (int i = 0; i < s.size(); i++)
        {
            
            if (s[i] == 'L')
            {
                position--;
            }
            else
            {
                position++;
            }
            time--;
            if (time == 0)
            {   
                break;
            }
            if (position == 0)
            {
                zeroFound = 1;
                currIndex = i;
                break;
            }
        }
        // cout << time << endl;
        if (time == 0)
        {
            if (position == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
            continue;
        }
        if (zeroFound == -1)
        {
            // cout<<"hi"<<endl;
            cout << 0 << endl;
        }
        else
        {
            int newPos = 0;
            int cycleLength = -1;
            for (int j = 0; j < n; j++)
            {
                if (time == 0)
                {
                    break;
                }

                if (s[j] == 'L')
                {
                    newPos--;
                }
                else
                {
                    newPos++;
                }

                if (newPos == 0)
                {
                    cycleLength = j + 1;
                    break;
                }
               
            }

            if (cycleLength == -1)
            {
                cout << 1 << endl;
            }
            else
            {
                ans = 1;
               
                ans += (time / cycleLength);
                cout << ans << endl;
            }
        }
    }
    return 0;
}