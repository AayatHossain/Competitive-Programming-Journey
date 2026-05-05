#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> x(n);
        vector<long long> y(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> y[i];
        }
        vector<long long> payMore;
        vector<long long> payLess;

        
        for (long long i = 0; i < n; i++)
        {
            long long diff = y[i] - x[i];
            if( diff >= 0){
                payMore.push_back(diff);
            }else{
                payLess.push_back(abs(diff));
            }
        }

        sort(payMore.begin(), payMore.end());
        sort(payLess.begin(), payLess.end());

        long long i = payMore.size() - 1;
        long long j = payLess.size() - 1;

        long long ans = 0;
        while(i >=0 && j >= 0){
            long long large = payMore[i];
            long long small = payLess[j];
            if(large >= small){
                j--;i--;ans++;
            }else{
                j--;
            }
        }
        
        if(i >= 0){
            ans += (i+1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}