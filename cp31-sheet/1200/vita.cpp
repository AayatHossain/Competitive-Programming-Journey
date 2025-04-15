#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        vector<long long> maxArr(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] > k)
        {
            cout << 0 << endl;
            continue;
        }
        long long first = a[0];
        long long mV = k + 1;
        long long diff = mV - first;
        for (long long i = 0; i < n; i++)
        {
            maxArr[i] = a[i] + diff;
        }

        vector<long long> prefSum(n);
        prefSum[0] = maxArr[0];
        for (long long i = 1; i < n; i++)
        {
            prefSum[i] = prefSum[i - 1] + maxArr[i];
        }
        // for(long long i = 0; i < n; i++){
        //     cout<<prefSum[i]<<" ";
        // }

        long long count = 0;
        for (long long i = 0; i < n; i++)
        {
            if (prefSum[i] > k)
            {
                long long extra = prefSum[i] - k;
                long long divide = extra / (i + 1);
                long long curr;

                if (extra % (i + 1) != 0)
                {
                    curr = maxArr[i] - divide - 1;
                    
                }
                else
                {
                    curr = maxArr[i] - divide;
                }
                if(curr < a[i]){
                    break;
                }

                count += (curr - a[i] + 1);
                // if (i == 1)
                // {
                //     cout << maxArr[i] << endl;
                //     cout << prefSum[i] << endl;
                //     cout << extra << endl;
                //     cout << divide << endl;
                //     cout << curr << endl;
                //     cout << curr - a[i] << "a" << endl;
                // }
            }
            else
            {
                long long curr = maxArr[i];
                count += (curr - a[i] + 1);
            }
        }
        cout<< count << endl;
    }
    return 0;
}