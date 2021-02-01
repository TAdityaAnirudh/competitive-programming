#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<long> rows;
    set<long> cols;

    int tests;
    int n;
    int m;
    int k;

    int r;
    int c;

    int i;
    long j;

    cin >> tests;

    while (tests--)
    {
        cin >> n >> m >> k;
        rows.clear();
        cols.clear();

        for (i = 0; i < k; i++)
        {
            cin >> r >> c;

            // each row has m horizontal bars
            // and m + 1 vertical bars
            // compute index of them and add/remove
            j = (r - 1) * (long)m + c;
            if (rows.find(j) == rows.end())
            {
                rows.insert(j);
            }
            else
            {
                rows.erase(j);
            }

            j = r * (long)m + c;
            if (rows.find(j) == rows.end())
            {
                rows.insert(j);
            }
            else
            {
                rows.erase(j);
            }

            // now columns
            j = (r - 1) * ((long)m + 1) + c;
            if (cols.find(j) == cols.end())
            {
                cols.insert(j);
            }
            else
            {
                cols.erase(j);
            }

            j = (r - 1) * ((long)m + 1) + c + 1;
            if (cols.find(j) == cols.end())
            {
                cols.insert(j);
            }
            else
            {
                cols.erase(j);
            }
        }

        cout << rows.size() + cols.size() << "\n";
    }

    return 0;
}
