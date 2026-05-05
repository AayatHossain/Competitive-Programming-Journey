#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    int si = 0, sj = 0;
    int i = 0, j = n - 1;
    int count = 0;
    
    while(i < j-1){
        si += a[i];
        sj += a[j];
        if(si==sj){
            i++;
            if(sum - 2*si==si){
                count++;
            }
        }else if(si < sj){
            i++;
        }else{
            j--;
        }
    }
    i = 0; j = n-1;
    while(i < j-1){
        si += a[i];
        sj += a[j];
        if(si==sj){
            i++;
            if(sum - 2*si==si){
                count++;
            }
        }else if(si < sj){
            i++;
        }else{
            j--;
        }
    }
    cout<<count<<endl;
    return 0;
}