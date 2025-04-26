#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin>>s;
        vector<int> a;
        for(int i = 0; i < s.size(); i++){
            a.push_back(s[i] - '0');
        }
        sort(a.begin(), a.end());
        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        int count = 9;
        string ans;
        for(int i = count; i >= 0; i--){
            for(int j = 0; j < a.size(); j++){
                if(a[j] >= i && a[j] != -1){
                    ans+=to_string(a[j]);
                    // cout<<a[j]<<" ";
                    a[j] = -1;
                    break;
                }
            }
        }
        cout<<ans<<endl;
            
    }
}