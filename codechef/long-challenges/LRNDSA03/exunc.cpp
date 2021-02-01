#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    int q;

    set<int> ranges;
    vector<int> values;

    int i;
    int j;
    int k;

    cin >> n >> q;

    cin >> j;
    values.push_back(j);
    ranges.insert(0);
    for (i = 1; i < n; i++)
    {
        cin >> j;
        values.push_back(j);
        if (values[i] % values[i - 1] != 0)
        {
            ranges.insert(i);
        }
    }

    // for (int i : ranges)
    // {
    //     cout << i << "\n";
    // }

    for (i = 0; i < q; i++)
    {
        cin >> j >> k;
        if (j == 1)
        {
            cin >> j;
            k--;
            values[k] = j;

            // update ranges
            if (k > 0 && values[k] % values[k - 1] != 0) ranges.insert(k);
            if (k < n - 1 && values[k + 1] % values[k] != 0) ranges.insert(k + 1);
            if (k > 0 && values[k] % values[k - 1] == 0) ranges.erase(k);
            if (k < n - 1 && values[k + 1] % values[k] == 0) ranges.erase(k + 1);
        }
        else
        {
            // cout << "Computing for " << k << "\n";

            // compute set of the value and print
            auto iter = ranges.upper_bound(k - 1);
            iter--;
            cout << (*iter) + 1 << "\n";
        }
    }

    return 0;
}