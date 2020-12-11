#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define min(X, Y) (((X) > (Y)) ? (Y) : (X))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define abs(X) ((X) > 0) ? (X) : (-1 * X)

using namespace std;

typedef struct _Range
{
    int min;
    int max;
} Range;

// global variables
int sheets_fl[100001];
int sheets_fr[100001];

int blocks_fl[100001];
int blocks_fr[100001];

char input[100001];

Range ranges[100001];

int max_ranges[100001];

bool compare_range(Range const& item1, Range const& item2)
{
    return item1.max < item2.max;
}

Range get_range(int magnet_pos, int k, int n)
{
    Range cur_range;

    int left_extreme = max(0, magnet_pos - k);
    int right_extreme = min(n - 1, magnet_pos + k);

    int left;
    int right;
    int mid;
    int attraction;

    // find left limit
    left = left_extreme;
    right = magnet_pos;

    while (right >= left)
    {
        mid = (right + left) / 2;

        // are there any blocks?
        if (blocks_fl[mid] != blocks_fl[magnet_pos] || blocks_fr[mid] != blocks_fr[magnet_pos])
        {
            // this means there are some blocks between magnet and this position (inclusive)
            left = mid + 1;
            mid++;
            continue;
        }

        // now compute if we can still attract
        attraction = k + 1 - (magnet_pos - mid) - (sheets_fl[magnet_pos] - sheets_fl[mid]);
        if (attraction == 0)
        {
            left = right = mid;
        }
        else if (attraction > 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cur_range.min = mid;

    left = magnet_pos;
    right = right_extreme;

    while (right >= left)
    {
        mid = (right + left) / 2;

        // are there any blocks?
        if (blocks_fl[mid] != blocks_fl[magnet_pos] || blocks_fr[mid] != blocks_fr[magnet_pos])
        {
            // this means there are some blocks between magnet and this position (inclusive)
            right = mid - 1;
            mid--;
            continue;
        }

        // now compute if we can still attract
        attraction = k + 1 - (magnet_pos - mid) - (sheets_fl[magnet_pos] - sheets_fl[mid]);
        if (attraction == 0)
        {
            left = right = mid;
        }
        else if (attraction > 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cur_range.max = mid;

    return cur_range;
}

int main()
{
    int tests;
    int n;
    int i;
    int j;
    int k;

    int blocks;
    int sheets;
    int magnet_count;

    scanf("%d", &tests);
    while (tests--)
    {
        scanf("%d %d", &n, &k);
        scanf("%s", input);

        for (i = 0; i <= n; i++)
        {
            max_ranges[i] = 0;
        }

        blocks = 0;
        sheets = 0;
        for (i = 0; i < n; i++)
        {
            if (input[i] == ':')
            {
                sheets++;
            }
            else if (input[i] == 'X')
            {
                blocks++;
            }

            blocks_fl[i] = blocks;
            sheets_fl[i] = sheets;
        }

        blocks = 0;
        sheets = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (input[i] == ':')
            {
                sheets++;
            }
            else if (input[i] == 'X')
            {
                blocks++;
            }

            blocks_fr[i] = blocks;
            sheets_fr[i] = sheets;
        }

        // figure out the ranges per magnet
        magnet_count = 0;
        for (i = 0; i < n; i++)
        {
            if (input[i] == 'M')
            {
                // find left and right edges and add it to ranges
                ranges[magnet_count] = get_range(i, k, n);

                magnet_count++;
            }
        }

        // sort the ranges by their ending
        sort(ranges, ranges + magnet_count, &compare_range);

        // do a memoization on length of string
        j = 0;
        for (i = 0; i < n; i++)
        {
            if (ranges[j].max < i)
            {
                while (ranges[j].max < i && j < magnet_count)
                {
                    j++;
                }
            }

            if (j < magnet_count)
            {
                if (ranges[j].max > i)
                {
                    max_ranges[i] = max_ranges[i - 1];
                }

                for (k = j; k < magnet_count && ranges[k].max == i; k++)
                {
                    if (ranges[k].min == 0 && max_ranges[i] == 0)
                    {
                        max_ranges[i] = 1;
                    }
                    else if (ranges[k].min > 0 && (max_ranges[ranges[k].min - 1] + 1) > max_ranges[i])
                    {
                        max_ranges[i] = max_ranges[ranges[k].min - 1] + 1;
                    }
                    else if (i > 0 && max_ranges[i] < max_ranges[i - 1])
                    {
                        max_ranges[i] = max_ranges[i - 1];
                    }
                }
            }
            else
            {
                max_ranges[i] = max_ranges[i - 1];
            }
        }

        // print the answer
        printf("%d\n", max_ranges[n - 1]);
    }

    return 0;
}
