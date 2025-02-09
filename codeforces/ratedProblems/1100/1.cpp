#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long num1 = n / 2;
        long long num2 = (n/2) + (n%2);
        long long count1 = 0,count2 = 0,minVal1,minVal2,sum1 = 0,sum2 = 0;
        while(num1 > 0){
            sum1 += num1 % 10;
            num1 = num1 / 10;
            count1++;
        }
        while(num2 > 0){
            sum2 += num2 % 10;
            num2 = num2 / 10;
            count2++;
        }
        minVal1 = 5 * count1;
        minVal2 = 5 * count2;
        
        // cout<<count1<<" "<<count2<<" ";

        if(sum1 >= minVal1 && sum2 >= minVal2 && count1==count2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}