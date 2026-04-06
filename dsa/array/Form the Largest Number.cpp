#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    int i = 0, j = n-1;
    int c = 0;
    while(i < j){
        if(a[i] < a[j]){
            i++;
            c++;
            a[i] += a[i-1];
        }else if(a[j] < a[i] ){
            j--;
            c++;
            a[j] += a[j+1];
        }else{
            i++;j--;
        }
    }
    cout<<c<<endl;
    return 0;
}