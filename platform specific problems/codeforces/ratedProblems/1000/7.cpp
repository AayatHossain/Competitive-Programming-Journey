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
       int a[n+1];
       a[0] = 0;
       int maxV = -1;
       int curr = 0;
       int count = 0;
       for(int i = 1; i <= n; i++){
            cin>>a[i];
            if(a[i] < a[i-1]){
                curr = a[i-1] - a[i];
                a[i] = a[i] + curr;
                maxV = max(maxV, curr);
                count++;
            }
       }
       if(maxV==-1){
       cout<<"ans"<<0<<endl;
       }else{
       cout<<"ans"<<(count+1)*maxV<<endl;
       }

    }
    return 0;
}
