#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, h;
        cin >> l >> h;

        int s = -1, e = a.size();
        int mid;
        while(s+1 < e){
            mid = (s + e) >> 1;
            if(a[mid] < l){
                s = mid;
            }else{
                e = mid;
            }
        }
        int low = e+1;

        s = -1, e = a.size();
        while(s+1 < e){
            mid = (s + e) >> 1;
            if(a[mid]<=h){
                s = mid;
            }else{
                e = mid;
            }
        }
        int high = s+1;


        //CAN ALSO BE SOLVED WITH STL
        // int low = lower_bound(a.begin(), a.end(), l) - a.begin();
        // int high = upper_bound(a.begin(), a.end(), h) - a.begin();
        // cout<<high<<"-"<<low<<endl;
        if(high < low){
            cout<<0<<" ";
        }else{
        cout<<high - low+ 1 <<" ";

        }
    }
    cout << endl;
    return 0;
}