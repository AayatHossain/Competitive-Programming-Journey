#include<bits/stdc++.h>
using namespace std;
#define int long long

string del(string t, int k, vector<int> &a){
    string temp = t;
    for(int i = 0; i < k; i++){
        temp[a[i]-1] = 'B';
    }
    string ans;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] != 'B'){
            ans += temp[i];
        }
    }
    // cout<<temp<<" "<<ans<<endl;
    return ans;
}
int ok(string t, string p){
    int i =0,j=0;
    int m = p.size();
    int n = t.size();
    if(m > n){
        return 0;
    }
    while( i < m && j < n){
        if(p[i] == t[j]){
            i++;
        }
        j++;
    }
    return i==m;
}

signed main(){
    string t,p;
    cin>>t>>p;
    vector<int> a(t.size());
    for(int i = 0; i < t.size(); i++){
        cin>>a[i]; 
    }

    int l = 0, r = t.size();
    int mid;
    while(r > l+1){
        mid = l+(r-l)/2;
        string s = del(t, mid, a);
        if(ok(s, p)){
            l = mid;
            // cout<<mid<<endl;

        }else{
            r = mid;
        }
    }
   
   cout<<l<<endl;

    return 0;
}