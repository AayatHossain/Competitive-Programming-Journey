#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n ; i++){
            cin>>a[i];
        }
        int count = -1; int total = 0;
        for(int i = n - 1; i >=0; i--){
            if(a[i]==i+1){
                count++; total += count;
                // cout<<count<<endl;
            }
        }
        cout<<total<<endl;
            
        
    }
    return 0;
}