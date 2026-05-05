#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(int l, int m, int r, vector<int> &a){
        vector<int> temp(r-l+1);
        int index = 0;
        int i = l, j = m+1;
        int cnt = 0;
        while(i <= m && j <= r){
            if(a[i] <= a[j]){
                temp[index] = a[i];
                i++;
            }else{
                temp[index] = a[j];
                cnt += (m-i+1);
                j++;
            }
            index++;
        }
        while(i <= m){
            temp[index] = a[i];
            i++;
            index++;
        }
        while(j <= r){
            temp[index] = a[j];
            j++;
            index++;
        }
        int k = 0;
        for(int i = l; i <= r; i++){
            a[i] = temp[k];
            k++;
        }
        return cnt;
    }

    int f(int l, int r, vector<int> &a){
        if(l >= r)return 0;

        int m = (l+r)/2;
        int v1 = f(l, m, a);
        int v2 = f(m+1,r,a);
        int v3 = merge(l,m,r,a);
        return v1+v2+v3;
    }

    int inversionCount(vector<int> &a) {
        int n = a.size();
        int v = f(0,n-1, a);
        return v;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.inversionCount(arr) << endl;

    return 0;
}