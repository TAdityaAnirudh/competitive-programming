#include <iostream>

using namespace std;

int main()
{
    int n;
    int m;

    int a_min;
    int b_max;
    int a_idx;
    int b_idx;

    int temp;

    cin >> n >> m;

    a_min == 1000000001;
    a_idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < a_min)
        {
            a_min = temp;
            a_idx = i;
        }
    }

    b_max = -1000000001;
    b_idx = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (temp > b_max)
        {
            b_max = temp;
            b_idx = i;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << a_idx << " " << i << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != a_idx)
        {
            cout << i << " " << b_idx << endl;
        }
    }

    return 0;
}