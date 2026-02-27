#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> c(n+1);
    for(int i= 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i= 1; i <= n; i++){
        cin>>b[i];
    }
    for(int i= 1; i <= n; i++){
        cin>>c[i];
    }

    // Prefix sum arrays for A, B, C
    vector<int> pa(n+1, 0);   // pa[i] = sum of A[1] to A[i]
    vector<int> pb(n+1, 0);   // pb[i] = sum of B[1] to B[i]
    vector<int> sc(n+1, 0);   // sc[i] = sum of C[i] to C[N]
    
    // Calculating prefix sums for A and B
    for(int i = 1; i <= n; i++){
        pa[i] = pa[i-1] + a[i];
        pb[i] = pb[i-1] + b[i];
    }

    // Calculating suffix sums for C (from C[N] to C[i])
    sc[n] = c[n];
    for(int i = n-1; i >= 1; i--){
        sc[i] = sc[i+1] + c[i];
    }

    // Now, we want to calculate the maximum possible value
    int mx = LLONG_MIN / 2;  // Use a large negative number
    int index = -1;

    // Loop through the valid values of y (y ranges from 2 to N-1)
    for(int i = 1; i < n; i++){
        int s = pb[i] + sc[i+1];
        if(s > mx){
            index = i;
            mx = s;
        }
    }

    // Now calculate the maximum possible value of (pa[x] - pb[x]) + mx
    int ans = LLONG_MIN / 2;
    for(int i = 1; i <= index; i++){
        int s = pa[i] - pb[i] + mx;  // Best x up to index
        ans = max(ans, s);
    }

    cout << ans << endl;
    return 0;
}