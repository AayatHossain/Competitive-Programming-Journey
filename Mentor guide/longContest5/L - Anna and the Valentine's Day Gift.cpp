#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+6;
vector<string> a;
vector<int> zeroes;
int n,m, total;
void calcZeroes(){
    for(int i = 0; i < n; i++){
        string t = a[i];
        int index = t.size()-1;
        while(index >= 0 && t[index] =='0'){
            zeroes[i]++;
            index--;
        }
    }
    // for(auto x: zeroes){
    //     cout<<x<<" ";
    // }
}

void solve(){
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        q.push({zeroes[i], a[i].size()});
    }
    int move = 1;
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if(move==1){
            q.push({0, p.second - p.first});
            move = 2;
        }else{
            total += p.second;
            move = 1;
        }
    }
}

signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        a = vector<string>(n);
        zeroes = vector<int>(n,0);
        total = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        calcZeroes();
        solve();
        if(total >= m+1){
            cout<<"Sasha"<<endl;
        }else{
            cout<<"Anna"<<endl;
        }

    }
    return 0;
}