class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        while(r-l > 1){
            int m = (l+r)/2;
            if(a[m] < a[r]){
                r = m;
            }else{
                l = m;
            }
        }
        if(a[l] < a[r])return a[l];
        return a[r];
    }
};