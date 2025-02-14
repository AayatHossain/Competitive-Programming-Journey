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
            int maxI = bS(start, end, b,max);
            int minI = bS(start, end, b, min);
            int startChanged = 0;
            int endChanged = 0;
            if(maxI==start){
                start++;
                startChanged = 1;
                max--;
            }
            if(maxI==end){
                end--;
                endChanged = 1;
                max--;
            }
            if(minI==start){
                start++;
                startChanged = 1;
                min++;
            }
            if(minI==end){
                end--;
                endChanged = 1;
                min++;
            }
            if(startChanged==0 && endChanged==0){
                cout<<min<<" "<<max<<endl;
                break;
            }
        }
    }
    return 0;
}