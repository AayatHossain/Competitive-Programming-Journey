#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int ans = a[0];
        int sum = a[0];
        int uselessSum = min(0, a[0]);
        for(int i = 1; i < n; i++){
            int j = abs(a[i]);
            int k = abs(a[i-1]);
            if((j%2)==(k%2)){
                sum = 0;
                uselessSum = 0;
            }
            sum += a[i];
            int maxSubArraySum = sum - uselessSum;
            ans = max(ans, maxSubArraySum);
            uselessSum = min(uselessSum, sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}