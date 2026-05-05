#include <bits/stdc++.h>
using namespace std;
// #define int long long
int b[2001][2001]; 
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
   
            b[0][i] = a[i];
        }
        int ms=n;
        for (int i = 1; i <= n; i++)
        {
            map<int, int> freq;
            for (int j = 0; j < n; j++)
            {
                freq[b[i - 1][j]]++;
            }
            bool f = 0;
            for (int j = 0; j < n; j++)
            {
                b[i][j] = freq[b[i - 1][j]];
            }
            for(int j = 0; j < n; j++){
                if(b[i][j]!=b[i-1][j]){
                    f=1;
                    break;
                }
            }
            if(!f){
                ms=i-1;break;
            }
        }

        // for(int i = 1; i < n; i ++){
        //     for(int j = 0; j < n; j++){
        //        cout<<b[i][j]<<" ";
        //     }
        //     cout<<endl;

        // }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int x, k;
            cin >> x >> k;
            if (k > ms)
                k = ms;
            cout << b[k][x - 1] << '\n';
        }
    }
    return 0;
}