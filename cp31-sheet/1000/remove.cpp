#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
       int n; cin>>n;
       vector<int> a(n);
       vector<int> b(n);
       for(int i = 0; i < n; i++){
        cin>>a[i];
       }
       for(int i = 0; i < n; i++){
        cin>>b[i];
       }
       if(n%2){
        int mid = n/2;
        if(a[mid]==b[mid]){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;

        }
       }else{
            int mid = n/2;
            int prevMid = mid - 1;
            map<int, int> s;
            s[a[mid]]++;
            s[a[mid-1]]++;
            s[b[mid]]++;
            s[b[mid-1]]++;
            int flag = 1;
            for(auto x: s){
                if(x.second < 2){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cout<<"Bob"<<endl;
            }else{
                cout<<"Alice"<<endl;

            }
       }
    }
    return 0;
}