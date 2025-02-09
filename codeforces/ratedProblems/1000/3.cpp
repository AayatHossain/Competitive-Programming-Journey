// https://codeforces.com/problemset/problem/2040/B

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int moves = 1, curr = 1, r = -1;
        while(curr < n){
            curr++;
            r = 2*curr;
            moves++;
            curr = r;
        }
        cout<<moves<<endl;
    }
    return 0;
}