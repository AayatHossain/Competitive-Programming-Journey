#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n, 1);
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            a[x - 1] = 0;
        }
        for (int l = 0; l < q; l++)
        {
            int david;
            cin >> david;
            david = david - 1;
            a[david] = 2;
            int i = david - 1;
            int j = david + 1;
            int left = -1;
            int right = -1;
            int iflag = 0;
            int jflag = 0;
            while (i >= 0 && j < n)
            {
                if (a[i] == 0 && iflag == 0)
                {
                    left = i;
                    iflag = 1;
                }
                if (a[j] == 0 && jflag == 0)
                {
                    right = j;
                    jflag = 1;
                }
                i--;
                j++;
            }
            if (i < 0)
            {
                while (j < n)
                {
                    if (a[j] == 0 && jflag == 0)
                    {
                        right = j;
                        jflag = 1;
                    }
                    j++;
                }
            }
            if (j >= n)
            {
                while (i >= 0)
                {
                    if (a[i] == 0 && iflag == 0)
                    {
                        left = i;
                        iflag = 1;
                    }
                    i--;
                }
            }
            int moves = 0;
            // cout<<"left"<<left<<endl;
            // cout<<"right"<<right<<endl;
            if (left != -1 && right != -1)
            {
                right++;
                left++;
                moves = (right - left) / 2;
            }
            else if (left == -1 && right != -1)
            {
                right++;
                moves = right - 1;
            }
            else
            {
                left++;
                // if(david == n-1){
                // moves = n - david + 1;
                // }else{
                //  moves = n - david;
                // }
                moves = n-left;
            }
            cout <<moves << endl;
            a[david] = 1;
            
        }
    }
    return 0;
}
