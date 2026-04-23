// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.

class Solution {
  public:
    int findStepKeyIndex(vector<int>& a, int k, int x) {
        // code here
        int n = a.size();
        int i = 0;
        while(i < n){
            if(a[i]==x)return i;
            int ni = abs(a[i]-x)/k;
            i += max(1, ni);
        }
        return -1;
        
    }
};