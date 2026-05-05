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
        long long n, m;
        cin >> n >> m;
        long long fixed = 0;
        vector<pair<long long,long long>> a(n);
        for (long long i = 0; i < n; i++)
        {
            long long cont = 0;
            long long score = 0;
            long long sum = 0;
            for(long long j = 0; j < m; j++){
                long long x;
                cin>>x;
                sum += x;
                cont += x;
                score += cont;
            }
            a[i] = make_pair(sum, score);
            // cout<<sum<<endl;
            fixed += score;
        }
        sort(a.begin(), a.end(), [](const pair<long long, long long> &p1, const pair<long long, long long> &p2) {
            return p1.first > p2.first;
        });
        
        // for(auto x: a){
        //     cout<<x.first<<endl;
        // }

        long long extra = 0;
        for(long long i = 0; i < n; i++){
            pair<long long,long long> x = a[i];
            extra = extra + (n-1-i)*x.first;

        }
        long long ans = fixed + (m*extra);
        cout<<ans<<endl;
    }
    return 0;
}