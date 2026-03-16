//ON AND O1 XOR METHOD, CAN BE SOLVED FOR ALL EVEN OCCURENCE AND 2 ODD OCCURENCE AS WELL

class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int n = a.size();
        vector<int> ans(2,0);
        unsigned int x = 0;
        for(int i = 0; i < n; i++){
            x^=a[i];
        }

        x = (x&(-x));

        for(int i = 0; i < n; i++){
            if(a[i] & x){
                ans[1] ^= a[i];
            }else{
                ans[0] ^= a[i];
            }
        }
        return ans;
    }
};