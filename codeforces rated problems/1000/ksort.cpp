#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
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
        int currentLarge = -1;
        vector<int> diff;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                currentLarge = a[i];
                // cout<<currentLarge<<endl;
                int j = i + 1;
                while (j < n && currentLarge >= a[j])
                {
                    diff.push_back(currentLarge - a[j]);
                    // cout<<currentLarge - a[j]<<endl;
                    j++;
                }
                // if(j < n && currentLarge < a[j]){
                //     currentLarge = a[j];
                // }
                i = j - 1;
            }
        }
        sort(diff.begin(), diff.end());
        // for(int i = 0; i < diff.size(); i++){
        //     cout<<diff[i]<<" ";
        // }
        int m = diff.size();
        int count = 0;
        if (m > 0)
        {
            count += diff[0] * (m + 1);
            for (int i = 1; i < m; i++)
            {
                int difference = diff[i] - diff[i - 1];
                // cout<<difference<<endl;
                count += difference * (m + 1 - i);
            }
        }

        cout<< count << endl;
    }

    return 0;
}