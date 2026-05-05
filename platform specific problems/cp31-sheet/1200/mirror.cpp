#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char val;
                cin>>val;
                int val2 = (int)(val - '0');
                a[i][j] = val2;
            }
        }
        int ans = 0;
        for(int i = 0; i < n/2; i++){
            int j = i; 
            while(j < n - i - 1){
                int c1 = 0;
                int c0 = 0;
                int v1 = a[i][j];
                int v2 = a[j][n-i-1];
                int v3 = a[n-i-1][n-j-1];
                int v4 = a[n-j-1][i];
                // cout<<v1<<v2<<v3<<v4<<endl;
                if(v1==1){
                    c1++;
                }else{
                    c0++;
                }

                if(v2==1){
                    c1++;
                }else{
                    c0++;
                }

                if(v3==1){
                    c1++;
                }else{
                    c0++;
                }

                if(v4==1){
                    c1++;
                }else{
                    c0++;
                }
                
                ans += min(c1, c0);
                j++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}