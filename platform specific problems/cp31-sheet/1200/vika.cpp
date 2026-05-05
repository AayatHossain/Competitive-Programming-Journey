#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> steps(n);
        vector<int> loc(k + 1, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            steps[i] = i - loc[a[i]] - 1;
            loc[a[i]] = i;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << steps[i] << " ";
        // }

        map<int, int> m;
        set<int> exists;
        for (int i = n - 1; i >= 0; i--)
        {
            int val = a[i];
            if (exists.find(val) == exists.end())
            {
                m[val] = n - i - 1;
                exists.insert(val);
            }
        }
        // for (auto x : m)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        vector<vector<int>> allSteps(k + 1);
        for (int i = 0; i < n; i++)
        {
            allSteps[a[i]].push_back(steps[i]);
        }

        for (auto x : m)
        {
            allSteps[x.first].push_back(x.second);
        }

        for (int i = 0; i <= k; i++)
        {
            if (allSteps[i].size() != 0)
            {
                sort(allSteps[i].begin(), allSteps[i].end());
            }
        }

        // for (int i = 0; i <= k; i++)
        // {
        //     if (allSteps[i].size() != 0)
        //     {
        //         cout << i << ": " << " ";
        //         for (auto x : allSteps[i])
        //         {
        //             cout << x << " ";
        //         }
        //         cout << endl;
        //     }
        // }

        for (int i = 0; i < allSteps.size(); i++)
        {
            if (allSteps[i].size() != 0)
            {
                int m = allSteps[i].size() - 1;
                int nV = (allSteps[i].at(m)) / 2;
                allSteps[i].at(m) = nV;
            }
        }
        for(int i = 0; i < allSteps.size(); i++){
            if(allSteps[i].size() != 0){
                sort(allSteps[i].begin(), allSteps[i].end());
            }
        }

        // for(int i = 0; i <= k; i++){
        //     if(allSteps[i].size() != 0){
        //         cout<<i<<": "<<" ";
        //         for(auto x: allSteps[i] ){
        //             cout<<x<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }

        int minV = INT_MAX;
        for (int i = 0; i < allSteps.size(); i++)
        {
            if (allSteps[i].size() != 0)
            {
                int m = allSteps[i].size() - 1;
                int val = (allSteps[i].at(m));
                minV = min(minV, val);
            }
        }
        cout<<minV<<endl;
    }
    return 0;
}