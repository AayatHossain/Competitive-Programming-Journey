#include<bits/stdc++.h>
using namespace std;
#define int long long
void print(const string &s){cout<<s<<endl;}template<typename T>void print(const vector<T>&v){cout<<"[ ";for(const auto&x:v)cout<<x<<" ";cout<<"]"<<endl;}template<typename T>void print(const vector<vector<T>>&vv){cout<<"[\n";for(const auto&v:vv){cout<<"  [ ";for(const auto&x:v)cout<<x<<" ";cout<<"]\n";}cout<<"]"<<endl;}template<typename T>void print(const set<T>&s){cout<<"{ ";for(const auto&x:s)cout<<x<<" ";cout<<"}"<<endl;}template<typename K,typename V>void print(const map<K,V>&m){cout<<"{\n";for(const auto&[k,v]:m)cout<<"  "<<k<<" : "<<v<<"\n";cout<<"}"<<endl;}template<typename T>void print(queue<T>q){cout<<"[ ";while(!q.empty()){cout<<q.front()<<" ";q.pop();}cout<<"]"<<endl;}
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int> pref(n);
        pref[0] = a[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + a[i];
        }
        int total = pref[n-1];
        int ans = LLONG_MIN;
        for(int i = 0; i < n-1; i++){
            int g = gcd(pref[i], total - pref[i]);
            ans = max(ans,g);
        }
        cout<<ans<<endl;
    }
    return 0;
}