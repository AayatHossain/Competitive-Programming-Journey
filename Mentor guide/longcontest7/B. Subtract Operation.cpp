#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int flag = 0;
        sort(a.begin(), a.end());
        for(int i = 0; i < n-1; i++){
            int val = a[i] + k;
            int index = lower_bound(a.begin()+i, a.end(), val) - (a.begin());
            
            if(index!=n && a[index]==val){
                flag = 1;
                break;
            }

        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}