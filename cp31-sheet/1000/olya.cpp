#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<vector<long long>> matrix(n, vector<long long>(2, -1));
        for(long long i = 0; i < n; i++){
            long long m;
            cin>>m;
            vector<long long> a(m);
            for(long long j = 0; j < m; j++){
                cin>>a[j];
            }
            sort(a.begin(), a.end());
            matrix[i][0] = a[0];
            matrix[i][1] = a[1];
        }
      

        long long mn1 = LLONG_MAX, mn2 = LLONG_MAX;
        for(long long i = 0; i < n; i++){
            mn1 = min(mn1, matrix[i][1]);
            mn2 = min(mn2 , matrix[i][0]);
        }
        long long flag = 1; long long sum = 0;
        
        for(long long i = 0; i < n; i++){
            if(matrix[i][1] == mn1 && flag == 1){
                flag = 0;
                continue;
            }
            sum += matrix[i][1];
            
        }
        sum += mn2;
        cout<<sum<<endl;
        
       
    }
    return 0;
}