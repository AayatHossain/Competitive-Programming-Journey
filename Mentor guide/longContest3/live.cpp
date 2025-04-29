#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int> b = a;
        sort(b.rbegin(), b.rend());
        int j = 0;
        cout<<b[0];
        int sum = 0;
        for(int i = n -1; i >= 1; i--){
            sum += a[i];
            if(a[i] == b[j]){
                j++;
            }
            sum += b[j];
            cout<<" "<<sum;
            sum -= b[j];
        }
        cout<<'\n';

    }
}