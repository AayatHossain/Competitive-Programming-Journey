#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n,l,r; cin>>n>>l>>r;
        vector<int> a(n+1);
        for(int i = 0; i <= n; i++){
            a[i] = i;
        }
        a[r] = l-1;
        vector<int> c(n+1,0);
        for(int i = 1; i <= n; i++){
            c[i] = a[i]^a[i-1];
        }
        for(int i = 1; i <= n; i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}