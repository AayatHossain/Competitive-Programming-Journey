
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string w;
        int p;
        cin >> w >> p;
        vector<pair<char, int>> a;
        int cost = 0;
        for (int i = 0; i < w.size(); i++)
        {   
            cost += w[i] - 'a' + 1;
            a.push_back({w[i], i+1});
        }
        // cout<<cost<<endl;
        sort(a.begin(), a.end());
        int j = a.size() - 1;
        while(cost > p){
            cost -= a[j].first - 'a' + 1;
            j--;
        }
        vector<pair<int,char>> ans;
        for(int i = 0; i <= j; i++){
            ans.push_back({a[i].second, a[i].first});
        }
        sort(ans.begin(), ans.end());
        string ans2;
        for(int i = 0; i < ans.size(); i++){
            ans2 += ans[i].second;
        }
        cout<<ans2<<endl;
    }

    return 0;
}