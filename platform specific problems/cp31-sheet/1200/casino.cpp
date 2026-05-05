#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
       long long n,m;cin>>n>>m;
       vector<vector<long long>> a(n, vector<long long>(m));
       for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            cin>>a[i][j];
        }
       }
       vector<vector<long long>> c(m, vector<long long>(n));
       for(long long i = 0; i < m; i++){
        vector<long long> b(n);
        for(long long j = 0; j < n; j++){
            b[j] = a[j][i];
        }
        sort(b.begin(), b.end());
        c[i] = b;
       }
    //    for(long long i = 0; i < m; i++){
    //     for(long long j = 0; j < n; j++){
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    //    }
    //    cout<<endl;

       vector<long long> sum;
       for(long long i = n-1; i >= 0; i--){
            long long sum1 = 0;
            for(long long j = 0; j < m; j++ ){
                sum1 += c[j][i];
            }
            sum.push_back(sum1);
       }
       for(long long i = 0; i < sum.size(); i++){
        cout<<sum[i]<<" ";
       }
       long long total = 0;
       long long size = sum.size();
       for(long long i = 0; i < sum.size(); i++){
            long long front = size - (i+1);
            long long prev = i;
            total -= prev*sum[i];
            total += front*sum[i];
       }
       
       cout<<total<<endl;
    }
    return 0;
}