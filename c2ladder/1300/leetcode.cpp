#include<bits/stdc++.h>
using namespace std;


    vector<int> lexSmallestNegatedPerm(int n, long long t) {
        vector<int> a(n);
        int s = n;
        int ct = 0;
        for(int i = 0; i < n; i++){
            a[i] = -s;
            s--;
            ct += a[i];
        }
        
        int f = 0;
        for(int i = n-1; i >= 0; i--){
            if(ct < t){
                ct+=2*abs(a[i]);
                a[i] = abs(a[i]);
            }
            // cout<<ct<<endl;
            if(ct==t){
                f=1;
                break;
            }
        }

        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int i = 0, j = n-1;
        for( i = 0; i < n; i++){
            if(a[i] > 0){
                break;
            }
        }
        while(i<=j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;j--;
        }
        if(f==0){
            a.clear();
        }
        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        if(a.size()!=0){
            return a;
        }


      
         s = 1;
         ct = 0;
        for(int i = 0; i < n; i++){
            a.push_back(-s);
            s++;
            ct += a[i];
        }
        
         f = 0;
        for(int i = n-1; i >= 0; i--){
            if(ct > t){
                ct-=2*abs(a[i]);
                a[i] = -a[i];
            }
            // cout<<ct<<endl;
            if(ct==t){
                f=1;
                break;
            }
        }

        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

     i = 0, j = n-1;
        for( i = 0; i < n; i++){
            if(a[i] < 0){
                break;
            }
        }
        while(i<=j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;j--;
        }
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
        if(f==0){
            a.clear();
        }
        
        return a;
    }

    int main(){
        int n,t; cin>>n>>t;
        vector<int> a = lexSmallestNegatedPerm(n,t);
        // for(auto x: a){
        //     cout<<x<<" ";
        // }

    }