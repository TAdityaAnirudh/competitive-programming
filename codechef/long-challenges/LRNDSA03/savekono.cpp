#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int tests;
    int n;
    int power;
    int count;
    int soldier;

    cin >> tests;

    while (tests--)
    {
        cin >> n;
        cin >> power;

        vector<int> soldiers(n);

        for (int i = 0; i < n; i++)
        {
            cin >> soldiers[i];
        }

        make_heap(soldiers.begin(), soldiers.end());

        count = 0;

        while (power > 0)
        {
            soldier = soldiers[0];
            power -= soldier;
            count++;

            if (soldier <= 0)
            {
                break;
            }

            pop_heap(soldiers.begin(), soldiers.end());
            soldiers.pop_back();

            soldiers.push_back(soldier / 2);
            push_heap(soldiers.begin(), soldiers.end());
        }

        if (power <= 0)
        {
            cout << count << "\n";
        }
        else
        {
            cout << "Evacuate\n";
        }
    }

    return 0;
}