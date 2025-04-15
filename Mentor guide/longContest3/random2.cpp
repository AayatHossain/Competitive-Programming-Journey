#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;cin>>k>>n;
        vector<int> a(k);
        int temp = n;
        int inc = 0;
        int indx = k-1;;
        while(indx >= 0){
            a[indx] = temp;
            inc++;
            temp-=inc;
            indx--;
            if(temp < indx+1){
                break;
            }
        }
        for(int i = 0; i <= indx; i++){
            a[i] = i+1;
        }
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}