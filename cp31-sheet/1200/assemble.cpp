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
        vector<long long> a;
        unordered_map<long long, long long> b;
        long long size = (n*(n-1))/2;
        for (long long i = 0; i < size; i++)
        {
            long long m;
            cin >> m;
            a.push_back(m);
            b[m] = b[m] + 1;
        }
        sort(a.begin(), a.end());
        auto last = unique(a.begin(), a.end());
        a.erase(last, a.end());
      
       

        vector<long long> ans(n);
        ans[n-1] = 1000000000;
       
        long long j = a.size() - 1;
        for(long long i = n - 2; i >= 0; i--){
           
            long long prev = n-i;
            long long next = n-i-1;
            long long x = a[j];
           
            

            long long required = ((prev*(prev-1))/2) - ((next*(next-1))/2);
           
            long long count = required;
            while(count <= b[x]){
                
                ans[i] = x;
              
                i--;
                
                prev = n-i;
                next = n-i-1;
                required = ((prev*(prev-1))/2) - ((next*(next-1))/2);
                count += required;
                
                
            }
            j--;
            i++;
            
            

        }
        for(long long i = 0; i < n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}