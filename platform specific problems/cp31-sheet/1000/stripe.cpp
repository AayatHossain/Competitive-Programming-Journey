#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int n, k; cin>>n>>k;
       string s; cin>>s;
        int cB = 0, cW = 0;
        for(int i = 0; i < k; i++){
            if(s[i]=='B'){cB++;}
            else{cW++;}
        }
        int ans = cW;
        int front = 0; int rear = k-1;
        // front++; rear++;
        while(rear < n ){
            if(s[front]=='B'){
                cB--;
            }else{
                cW--;
            }
            front++;rear++; if(rear==n){break;}
            if(s[rear]=='B'){
                cB++;
            }else{
                cW++;
            }
            ans = min(ans, cW);
            
        }
        cout<<ans<<endl;
    }
    return 0;
}