https://leetcode.com/problems/find-the-duplicate-number/description/
ON AND O1. FLOYDS CYCLE DETECTION

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        int l = -1;
        for(int i = 0; i < n; i++){
            if(a[i]!=i){
                l=a[i];
                break;
            }
        }
        if(l==-1)return -1;
        int r = l;
        int l1 = l;
        while(1){
            l = a[l];
            r = a[a[r]];
            if(l==r){
                break;
            }
        }
        while(l1!=l){
            l = a[l];
            l1 = a[l1];
        }
        return l;
    }
};

//ON AND ON USING ARRAY/HASHMAP ALSO POSSIBLE.