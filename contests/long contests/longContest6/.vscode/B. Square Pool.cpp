#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            int sx, sy, rx, ry, nx, ny;
            if (dx == 1 && dy == 1)
            {
                sx = s;
                sy = s;
                rx = abs(x - sx);
                ry = abs(y - sy);
                if (rx == ry)
                {
                    nx = x + rx * dx;
                    ny = y + rx * dy;
                    if (nx == sx && ny == sy)
                    {
                        count++;
                    }
                }
            }
            else if (dx == -1 && dy == -1)
            {
                sx = 0;
                sy = 0;
                rx = abs(x - sx);
                ry = abs(y - sy);
                if (rx == ry)
                {
                    nx = x + rx * dx;
                    ny = y + rx * dy;
                    if (nx == sx && ny == sy)
                    {
                        count++;
                    }
                }
            }
            else if (dx == 1 && dy == -1)
            {
                sx = s;
                sy = 0;
                rx = abs(x - sx);
                ry = abs(y - sy);
                if (rx == ry)
                {
                    nx = x + rx * dx;
                    ny = y + rx * dy;
                    if (nx == sx && ny == sy)
                    {
                        count++;
                    }
                }
            }
            else
            {
                sx = 0;
                sy = s;
                rx = abs(x - sx);
                ry = abs(y - sy);
                if (rx == ry)
                {
                    nx = x + rx * dx;
                    ny = y + rx * dy;
                    if (nx == sx && ny == sy)
                    {
                        count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}