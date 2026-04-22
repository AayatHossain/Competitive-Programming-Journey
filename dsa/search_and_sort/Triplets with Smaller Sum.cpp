https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1



class Solution {
  public:
    int countTriplets(int s, vector<int>& a) {
        // code here
        int n = a.size();
        int c = 0;
        sort(a.begin(),a.end());
        for(int i = 0; i < n-2; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int v = a[i]+a[j]+a[k];
                if(v < s){
                    c += (k-j);
                    j++;
                }else{
                    k--;
                }
            }
        }
        return c;
    }
};