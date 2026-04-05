class Solution {
  public:
    void reverseArray(vector<int> &a) {
        // code here
        int n = a.size();
        for(int i = 0; i < n/2; i++){
            int temp = a[i];
            a[i] = a[n-i-1];
            a[n-i-1] = temp;
        }
    }
};