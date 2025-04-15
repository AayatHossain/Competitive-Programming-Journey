#include<bits/stdc++.h>
using namespace std;
// #define int long long
bool ok(vector<int>& a, int mid) {
    int i = 0, j = a.size() - mid - 1;
    // if(j > 0 && a[i]*2 >= a[j]){
    //     return true;
    // }
    if(j < 0 || j >= a.size()){
        return false;
    }
    while(j < a.size() && i < a.size()){
       
        if(a[i]*2 >= a[j]){
            return true;
        }
        i++;j++;
    }
    return false;
}
int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    
        int n;cin>>n;vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int l = -1, r = n-1;
        int mid;
        while(r>l+1){
            mid = l + (r-l)/2;
            if(ok(a,mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout<<r<<'\n';
        

    return 0;
}