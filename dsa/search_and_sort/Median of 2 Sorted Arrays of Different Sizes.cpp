//log(min(n,m)) and 1

class Solution {
    
    double f(vector<int> &a, vector<int> &b){
        int n = a.size();
        int m = b.size();
        if(n > m)return f(b,a);
        
        int k = (n+m+1)/2;
        int l = 0, r = n;
        int m1,m2;
        while(l<=r){
            m1 = l+(r-l)/2;
            m2 = k - m1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(m1 > 0)l1=a[m1-1];
            if(m1 < n)r1 = a[m1];
            
            if(m2 > 0)l2 = b[m2-1];
            if(m2 < m)r2 = b[m2];
            
            if(l1 > r2){
                r= m1-1;
            }else if(l2 > r1){
                l = m1+1;
            }else{
                if((n+m)&1)return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
    }

  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // code here
        return f(a,b);
    }
};