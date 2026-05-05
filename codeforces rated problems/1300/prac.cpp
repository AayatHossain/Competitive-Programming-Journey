#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2}};
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int c = 0;
        for (auto m : moves)
        {
            int nx = x + m.first;
            int ny = y + m.second;
            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8)
            {
                c++;
            }
        }
        cout << c << endl;
    }
}