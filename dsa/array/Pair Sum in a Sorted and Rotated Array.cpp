// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& a, int t) {
        // code here
        int l = -1, r = -1;
        int n = a.size();
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                l = i; r = i-1;
                break;
            }
        }
        if(l==-1){
            l=0; r = n-1;
        }
        // cout<<l<<" "<<r<<endl;
        while(l != r){
            if(a[l]+a[r] < t){
                l++;
                if(l==n)l=0;
                // l = (l+1)%n for cyclic index change also applicable
            }else if(a[l]+a[r] > t){
                r--;
                if(r==-1)r=n-1;
                // r = (r-1+n)%n also doable
            }else{
                return true;
            }
        }
        return false;
        
    }
};