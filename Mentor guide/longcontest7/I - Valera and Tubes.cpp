#include <iostream>
#include <vector>
using namespace std;

void printSpiralOrder(int n, int m, int k)
{

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    int total = n * m;
    int used = 0;

    int count = 0;

    while (top <= bottom && left <= right)
    {

        for (int col = left; col <= right; ++col)
        {
            if (count == 0 && k > 1)
            {

                cout << 2 << " ";
            }
            if (count == 0 && k == 1)
            {
                cout << total - used << " ";
            }
            cout << top + 1 << " " << col + 1 << " ";
            used++;
            count++;
            if (count == 2 && k != 1)
            {
                count = 0;
                k--;
                cout << endl;
            }
        }
        top++;

        for (int row = top; row <= bottom; ++row)
        {
            if (count == 0 && k > 1)
            {

                cout << 2 << " ";
            }
            if (count == 0 && k == 1)
            {
                cout << total - used << " ";
            }
            cout << row + 1 << " " << right + 1 << " ";
            used++;

            count++;
            if (count == 2 && k != 1)
            {
                k--;
                count = 0;
                cout << endl;
            }
        }
        right--;

        if (top <= bottom)
        {
            for (int col = right; col >= left; --col)
            {
                if (count == 0 && k > 1)
                {

                    cout << 2 << " ";
                }
                if (count == 0 && k == 1)
                {
                    cout << total - used << " ";
                }
                cout << bottom + 1 << " " << col + 1 << " ";
                used++;

                count++;
                if (count == 2 && k != 1)
                {
                    k--;

                    count = 0;
                    cout << endl;
                }
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int row = bottom; row >= top; --row)
            {
                if (count == 0 && k > 1)
                {
                    cout << 2 << " ";
                }
                if (count == 0 && k == 1)
                {
                    cout << total - used << " ";
                }
                cout << row + 1 << " " << left + 1 << " ";
                used++;

                count++;
                if (count == 2 && k != 1)
                {
                    count = 0;
                    k--;
                    cout << endl;
                }
            }
            left++;
        }
    }

    cout << endl;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    printSpiralOrder(n, m, k);

    return 0;
}
