#include <iostream>
#include <vector>
using namespace std;

int numOfSubsets(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(k+1,0);
        for(int i = 0; i < n; i++){
            for(int j=k; j>=0; j--){
                if(a[i]==j){
                    dp[j]++;
                }else{
                    int q = j/a[i];
                    if(q*a[i]==j && dp[q]!=0){
                        dp[j] += dp[q];
                    }
                }
            }
        }
        int c= 0;
        for(int i = 0; i <=k; i++){
            if(dp[i])c+=dp[i];
        }
        return c;
        
    }

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = numOfSubsets(a, k);
    cout << "Number of subsets: " << result << endl;

    return 0;
}