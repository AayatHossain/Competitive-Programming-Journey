#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<pair<long long,long long>> a(n);
        vector<pair<long long,long long>> b(n);
        vector<pair<long long,long long>> c(n);
        for(long long i = 0; i < n; i++){
            long long m;
            cin>>m;
            a[i] = make_pair(m, i);
        }
        for(long long i = 0; i < n; i++){
            long long m;
            cin>>m;
            b[i] = make_pair(m, i);
        }
        for(long long i = 0; i < n; i++){
            long long m;
            cin>>m;
            c[i] = make_pair(m, i);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
       long long maxSum = -1;
       for (int i = n-3; i < n; i++) {
        for (int j = n-3; j < n; j++) {
            for (int k = n-3; k < n; k++) {
                unordered_set<long long> uniqueSecondValues = {a[i].second, b[j].second, c[k].second};
                
                if (uniqueSecondValues.size() == 3) { 
                    long long sum = a[i].first + b[j].first + c[k].first;
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }
        
        cout<<maxSum<<endl;
    }
    return 0;
}