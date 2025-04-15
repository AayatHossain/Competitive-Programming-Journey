#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{   int c = 1;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;vector<int>a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        sort(a.begin(), a.end());
        int count = 0;
        for(int i = 0; i < n-2; i++){
            for(int j = n-1; j >= i + 2; j--){
                int A = a[i], C = a[j];
                int l = i, r = j;
                while(r > l + 1){
                    int mid = l + (r-l)/2;
                    if(C < A + a[mid]){
                        r = mid;
                    }else{
                        l = mid;
                    }
                }
                // cout<<i<<"-" <<j<<"-"<<r<<endl;
                // r--;
                count += j-r;

                
            
            }
        }

        cout<<"Case "<<c<<": "<<count<<endl;
        c++;
    }
    
    return 0;
}