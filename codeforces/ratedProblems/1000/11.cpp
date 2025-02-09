
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int s = 600;
        cout<<600<<" ";
        for(int i = 2; i <= n; i++){
            int val;
            cin>>val;
            s+=val;
            cout<<s<<" ";
        }
        cout<<endl;

    }
    return 0;
}