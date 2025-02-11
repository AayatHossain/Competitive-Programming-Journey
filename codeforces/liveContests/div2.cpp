#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin >> t;
    while (t--)
    {
       int n;
       cin>>n;
       vector<int> a(n);
       vector<int> count(n+1, 0);
       for(int i = 0; i < n; i++){
        cin>>a[i];
        count[a[i]]++;
       }
       int flag = 1;
       for(int i = 0; i < n; i++){
        if(count[i]==1){
            flag = 0;
            break;
        }else if(count[i]  != 0){
            int rem = count[i];
            count[i] = 2;
            count[i + 1] += rem - 2;
        }
       }
       if(!flag){
        cout<<"NO"<<endl;
       }else{
            for(int i = 0; i <= n; i++){
                if(count[i] % 2 != 0){
                    cout<<"NO"<<endl;
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cout<<"YES"<<endl;
            }
       }
       
    }
    return 0;
}