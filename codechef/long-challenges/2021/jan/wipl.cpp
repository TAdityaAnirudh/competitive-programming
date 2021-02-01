#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100000];
int temp_dp[100000];
int previous[100000];

int heights[40001];
int used_boxes[40001];

int main()
{
    int tests;
    int n;
    int k;
    int i;
    int j;
    int l;
    int tracy_height;
    int count;
    int least_count;
    int max_dp;
    int found;
    int cur_height;

    scanf("%d", &tests);
    while (tests--)
    {
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &heights[i]);
        }

        // sort in descending
        sort(heights, heights + n);
        for (j = 0; j < n/2; j++)
        {
            l = heights[j];
            heights[j] = heights[n - 1 - j];
            heights[n - 1 - j] = l;
        }

        if (n == 1)
        {
            printf("-1\n");
            continue;
        }

        if (heights[1] >= k)
        {
            printf("2\n");
            continue;
        }

        if (heights[0] >= k)
        {
            // find greedy and continue
            tracy_height = 0;
            count = 1;
            j = 1;
            while (tracy_height < k && j < n)
            {
                count++;
                tracy_height += heights[j];
                j++;
            }

            if (tracy_height >= k)
            {
                printf("%d\n", count);
            }
            else
            {
                printf("-1\n");
            }
            
            continue;
        }

        // default to DP case
        max_dp = 2 * k;
        for (i = 0; i < 100000; i++)
        {
            dp[i] = temp_dp[i] = n + 1;
        }

        for (i = 0; i < n; i++)
        {
            dp[heights[i]] = 1;
            previous[heights[i]] = i;

            for (j = heights[i] + 1; j < max_dp; j++)
            {
                if ((temp_dp[j - heights[i]] + 1) < dp[j])
                {
                    dp[j] = temp_dp[j - heights[i]] + 1;
                    previous[j] = i;
                }
            }

            for (j = heights[i]; j < max_dp; j++)
            {
                temp_dp[j] = dp[j];
            }
        }

        // now find a combination
        found = 0;
        least_count = n + 1;

        for (j = k; j < max_dp; j++)
        {
            if (dp[j] < n && dp[j] < least_count)
            {
                for (i = 0; i <= 40000; i++)
                {
                    used_boxes[i] = 0;
                }

                cur_height = j;
                while (cur_height > 0)
                {
                    used_boxes[previous[cur_height]] = 1;
                    cur_height -= heights[previous[cur_height]];
                }

                // now do greedy
                tracy_height = 0;
                count = dp[j];
                i = 0;

                while ((tracy_height < k) && (i < n))
                {
                    if (!used_boxes[i])
                    {
                        tracy_height += heights[i];
                        count++;
                    }

                    i++;
                }

                if (tracy_height >= k)
                {
                    found = 1;

                    if (count < least_count)
                    {
                        least_count = count;
                    }
                }
            }
        }

        if (found)
        {
            printf("%d\n", least_count);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
