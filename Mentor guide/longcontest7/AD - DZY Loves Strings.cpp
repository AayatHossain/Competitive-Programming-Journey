#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){ 
    string s;cin>>s;
    int k;cin>>k;
    vector<int>a(26);
    for(int i = 0; i < 26; i++){
        cin>>a[i];
    }
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        c += a[(s[i] - 'a')]*(i+1);
    }
    // cout<<c<<endl;
    int i = s.size()+1;
    int mx = *max_element(a.begin(), a.end());
    while(k > 0){
        c += mx*i;
        i++;
        k--;
    }
    cout<<c<<endl;
    return 0;
}