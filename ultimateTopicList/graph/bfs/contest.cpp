#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k; cin>>n>>k;
        vector<int> a(n);
        vector<int> b(k);
        for(int i =0;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0; i < k; i++){
            cin>>b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int j =0;
        int cost = 0;
        for(int i =n-1; i>=0; i--){
            if(j==b.size()){
                cost+= a[i]; continue;
            }
            int x = b[j];
            // cout<<x<<endl;
            if(x <= i+1){
                while(x>0){
                    if(x != 1){
                        cost += a[i];
                    }
                    x--; i--;
                }
                i++;
                j++;
            }else{
                cost+=a[i];
            }
        }
        cout<<cost<<endl;
    }
}
