https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
//O(NLOGN+MLOGM) AND O1, TWO POINTERS.

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


//O(m+n)*O(log(m+n)) and O1. GAP METHOD

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        
        int n = a.size();
        int m = b.size();
        
        int gap = (n+m+1)/2;
        while(1){
            int left = 0, right = gap;
            while(right < n + m){
                if(left < n && right < n && a[left] > a[right]){
                    swap(a[left],a[right]);
                }else if(left < n && right >= n && a[left] > b[right-n]){
                    swap(a[left],b[right-n]);
                }else if(left >= n && right >= n && b[left-n] > b[right-n]){
                    swap(b[left-n],b[right-n]);
                }
                left++;right++;
            }
            if(gap==1)break;
            gap = (gap+1)/2;
        }
        
        return;
        
    }
};