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
        vector<vector<int>> a(n, vector<int>(4));
        
        for(int i = 0; i < n; i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
        }
        int n0 = 0, n1 = 0, cos = 0;
        for(int i = 0; i < n; i++){
            int aa = a[i][0], b= a[i][1], c=a[i][2], d = a[i][3];
            if(aa < c){
                n0 += c - aa;
            }
            if(b < d){
                n1 += d - b;
            }
            // if(aa==0 && (b > d)){
            //     cos += (b - d);
            // }

            if(aa >= c && b >= d){
                int m = aa - c;
                int l1 = b - m;
                if(l1 > d){
                    cos += (m - d);
                }
            }
        }
        // cout<<n0<<" "<<n1<<" "<<cos<<endl;
        int m1 = n1 - cos;
        int moves = n0 + m1*2;
        cout<<moves<<endl;
    }
    return 0;
}