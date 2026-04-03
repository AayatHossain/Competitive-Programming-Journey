// static bool compare(pair<pair<int,int>,int> a, 
//     pair<pair<int,int>,int> b){
//         pair<int,int> range1 = a.first;
//         pair<int,int> range2 = b.first;
        
//         if(range1.first / blk != range2.first / blk)
//             return range1.first / blk < range2.first / blk;

//         return range1.second < range2.second;
// }

// this is is the non zigzag comparator where r keeps increasing.
// in zigzag, r is like this is 1 and 2 block - 5 7 9, 8 5 4. increase then decrease. for lest pointer movement





class Solution {

  public:
    static int blk;
    static bool compare(pair<pair<int,int>,int> a, 
    pair<pair<int,int>,int> b){
        pair<int,int> range1 = a.first;
        pair<int,int> range2 = b.first;
        
        if(range1.first / blk != range2.first / blk)
            return range1.first / blk < range2.first / blk;

        if((range1.first / blk) & 1)
            return range1.second > range2.second;

        return range1.second < range2.second;
    }
    
    vector<int> solveQueries(vector<int> a, vector<vector<int>> qu, int k) {
        // Code here
        int c = 0;
        int n = a.size();
        int m = qu.size();
        blk = sqrt(n);
        vector<pair<pair<int,int>,int>> q;
        for(int i = 0; i < m; i++){
            q.push_back({{qu[i][0]-1,qu[i][1]-1},i});
        }
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            mx = max(mx, a[i]);
        }
        sort(q.begin(),q.end(), compare);
       
        vector<int> mm(mx+1);
        vector<int> ans(m,0);
        
        int cl = 0, cr = -1;
        int ck = 0;
        for(int i = 0; i < m; i++){
            int l = q[i].first.first;
            int r = q[i].first.second;
            int index = q[i].second;
            
            while(cl > l){
                cl--;
                mm[a[cl]]++;
                if(mm[a[cl]]==k)ck++;
              
            }
            while(cr < r){
                cr++;
                mm[a[cr]]++;
                if(mm[a[cr]]==k)ck++;
                
            }
            while(cl < l){
                
                if(mm[a[cl]]==k)ck--;
                mm[a[cl]]--;
                cl++;
            }
            while(cr > r){
                
                if(mm[a[cr]]==k)ck--;
                mm[a[cr]]--;
                cr--;
            }
            ans[index] = ck;
        }
        
        return ans;
    }
};

int Solution::blk;