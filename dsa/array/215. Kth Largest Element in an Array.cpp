//NLOGK AND K SOLUTION. USING MIN HEAP LIKE 1 2 3 4 5
class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < a.size(); i++){
            pq.push(a[i]);
            if(pq.size() > k)pq.pop();
        }
        return pq.top();
    }
};


//AVERAGE = 0N , WORST = ONSQUARE. SPACE = O1. QUICKSORT MODIFIED
class Solution {
public:
    int part(vector<int> &a, int l, int r){
        int p = a[r];
        int i = l;
        for(int j = l; j < r; j++){
            if(a[j] > p){
                swap(a[j],a[i]);
                i++;
            }
        }
        swap(a[i],a[r]);
        return i;
    }

    int qs(vector<int>&a, int l, int r, int k){
        if(l>r)return -1;

        int pi = part(a,l,r);
        if(pi==k){
            return a[pi];
        }else if(k < pi){
            return qs(a,l,pi-1,k);
        }else{
            return qs(a,pi+1,r,k);
        }
    }

    int findKthLargest(vector<int>& a, int k) {
        int v = qs(a,0,a.size()-1,k-1);
        return v;
    }
};