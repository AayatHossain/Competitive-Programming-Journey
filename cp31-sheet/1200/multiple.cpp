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
        string str;
        cin >> str;
        vector<long long> s(n + 1);
        vector<long long> t(n + 1);
        unordered_set<long long> cant;
        for (long long i = 1; i <= n; i++)
        {
            s[i] = i;
            long long val = (long long)(str[i - 1] - '0');
            t[i] = val;
            if (val == 1)
            {
                cant.insert(i);
            }
        }
        long long ans = 0;
        // for(long long i = 1; i <=n; i++){
        //     cout<<s[i]<<" ";
        // }
        // cout<<endl;
        // for(long long i = 1; i <=n; i++){
        //     cout<<t[i]<<" ";
        // }
        // cout<<endl;
        for (long long i = 1; i <= n; i++)
        {
            // for(long long k = 1; k<=n; k++){
            //     cout<<s[k]<<" ";
            // }
            // cout<<endl;
            if ((cant.find(s[i]) == cant.end()))
            {
                long long j = i;
                long long curr = 0;
                long long val = i;
                while (j <= n)
                {
                    
                     curr += val;
                    
                    if(curr > n){
                        break;
                    }else{
                        if(cant.find(s[curr])!=cant.end()){
                            cant.insert(val);
                            break;
                        }else{
                            if(s[curr] != 0){
                                s[curr] = 0;
                                ans += val;
                            }
                           
                            
                        }
                    }
                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}