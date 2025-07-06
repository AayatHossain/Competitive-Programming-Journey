#include <bits/stdc++.h>
using namespace std;
#define int long long
int N = 1001;
vector<bool> a(N, true);
void sieve()
{
    a[0] = false;
    a[1] = false;
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (a[i])
        {
            for (int j = i*i; j <= N; j += i)
            {
                a[j] = false;
            }
        }
    }
}
signed main()
{
    int t;cin>>t;
    sieve();
    while(t--){
        int n;cin>>n;
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        int mx = LLONG_MIN/2;
        int index = -1;
        for(int i = n-1; i >= 0; i--){
            if(a[b[i]]){
                index = i;
                break;
            }
        }
        if(index != -1){
            int index2 = -1;
            for(int i = index-1; i>=0; i--){
                if(gcd(b[i], b[index])==1){
                    index2 = i;
                    break;
                }
            }
            if(index2 != -1){
                mx = max(mx, index + index2 + 2);
            }
        }
        for(int i = 0; i < n; i++){
            if(b[i]==1){
                mx = max(mx, i+i+2);
            }
        }



         index = -1;
        for(int i = n-1; i >= 0; i--){
            if(!a[b[i]]){
                index = i;
                break;
            }
        }
        if(index != -1){
            int index2 = -1;
            for(int i = index-1; i>=0; i--){
                if(gcd(b[i], b[index])==1){
                // cout<<b[i]<<endl;

                    index2 = i;
                    break;
                }
            }
            if(index2 != -1){
                // cout<<"Ho";
                mx = max(mx, index + index2 + 2);
            }
        }

        if(mx==LLONG_MIN/2){
            mx = -1;
        }





        cout<<mx<<endl;
    }
    return 0;
}