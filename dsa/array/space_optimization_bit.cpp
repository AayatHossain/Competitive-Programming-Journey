#include<bits/stdc++.h>
using namespace std;


void setbit(int a[], int num){
    int numIndex = (num >> 5); // num / 32, to check which block is num present in
    int numbit = (num & 31); // num % 32, to check which bit num should be alloted
    a[numIndex] = (a[numIndex] | (1<<numbit)); 
}

bool checkbit(int a[], int num){
    int numIndex = (num >> 5);
    int numbit = (num & 31);
    if(a[numIndex] & (1<<numbit)){
        return true;
    }
    return false;
}

signed main(){
    int a,b; cin>>a>>b;
    int n = (b-a) + 1;
    int* arr = new int[(n/32) + 1]();
    for(int i = a; i <=b; i++){
        if(i%2 == 0 || i%5 == 0){
            setbit(arr,i-a);
        }
    }
    for(int i = a; i <= b; i++){
        if(checkbit(arr,i-a)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}