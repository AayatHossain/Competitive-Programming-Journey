#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(vector<int> a, int w, int c){
    int res=0;
    for(int i = 0; i < a.size(); i++){
        int curr = (a[i] + 2*w)*(a[i] + 2*w);
        res += curr;
        if(res > c){
            return res;
        }
    }
    return res;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c; cin>>n>>c;
        vector<int> a(n);
        int sum = 0, sq = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            sum += a[i];
            sq += a[i]*a[i];
        }
        
        int insRoot = ((sum*sum)/(n*n)) - ((sq - c)/n);
        int root = sqrt(insRoot);
        int deno = root - (sum/n);
        int res = deno/(2); 
       
        cout<<res<<endl;
    }
    return 0;
}