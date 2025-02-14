#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<pair<int,int>> b;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            b.push_back(make_pair(a[i], i));
        }
        sort(b.begin(), b.end());
        int start = 0;
        int end = n-1;
        int max = n;
        int min = 1;
        while(start < end){
            int maxI = bS(start, end, b);
            int minI = bS(start, end, b);
            if(maxI==start){
                start++;
            }
            if(maxI==end){
                end--;
            }
        }
    }
    return 0;
}