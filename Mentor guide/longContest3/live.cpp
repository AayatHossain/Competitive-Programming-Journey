#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;vector<int> a(n);
        int small = LLONG_MAX;
        int smallIndex = -1;
        for(int i = 0;i < n; i++){
            cin>>a[i];
            if(abs(a[i]) < small){
                smallIndex = i;
                small = abs(a[i]);
            }
        }
        // cout<<small<<endl;
        for(int i = n - 2; i >= smallIndex; i--){
            if(a[i] >= 0 && a[i+1] >= 0){continue;}
            if(a[i] <= 0 && a[i+1] <= 0){
                a[i] = abs(a[i]);
                a[i+1] = abs(a[i+1]);
            }else if(a[i] < 0){
                continue;
            }else{
                a[i] = - a[i];
                a[i+1] = abs(a[i+1]);
            }
           
        }
        // for(int i = 0; i < n; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 1; i <= smallIndex; i++){
            if(a[i] >= 0 && a[i-1] >= 0){continue;}
            if(a[i] <= 0 && a[i-1] <= 0){
                a[i] = abs(a[i]);
                a[i-1] = abs(a[i-1]);
            }else if(a[i] < 0){
                continue;
            }else{
                a[i] = - a[i];
                a[i-1] = abs(a[i-1]);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        int s =0 ;
        for(int i = 0; i < n; i++){
            s+=a[i];
        }
        cout<<s<<endl;

    }
}