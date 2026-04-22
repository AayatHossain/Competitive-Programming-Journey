https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
//ONLOGN AND O1, TWO POINTERS.

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        
        int n = a.size();
        int m = b.size();
        int i = n-1, j = 0;
        while(i >= 0 && j < m && a[i] > b[j]){
            int temp = a[i];
            a[i] = b[j];
            b[j] = temp;
            i--; j++;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return;
        
    }
};