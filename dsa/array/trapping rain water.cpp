//ON AND O1
class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int lm = a[0];
        int rm = a[n-1];
        int l = 1, r = n-2;
        int c = 0;
        while(l <= r){
            if(lm <= rm){
                c += max(0, lm - a[l]);
                lm = max(a[l],lm);
                l++;
            }else{
                c+=max(0, rm - a[r]);
                rm = max(rm,a[r]);
                r--;
            }
        }
        return c;
    }
};




//ON AND ON 
class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> l(n);
        vector<int> r(n);
        l[0]=0;
        for(int i = 1; i < n; i++){
            l[i] = max(l[i-1],a[i-1]);
        }
        r[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            r[i] = max(r[i+1],a[i+1]);
        }

        int c = 0;
        for(int i = 1; i < n-1; i++){
            int level = min(l[i],r[i]);
            if(level <= a[i])continue;
            c+= level - a[i];
        }
        return c;
    }
};