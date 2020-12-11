#include <stdio.h>

long long int vals[100001];
long long int profit[100001];
long long int MOD = 1000000007;

int main()
{
    int tests;
    int n;
    int q;
    long long int r;
    long long int ans;
    int i;
    int j;

    scanf("%d", &tests);

    while (tests--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &vals[i]);
        }

        ans = 0;

        if (vals[0] == 1)
        {
            // chef has to give up
            for (j = 0; j < n; j++)
            {
                profit[j] = 1;
            }
        }
        else
        {
            for (j = 0; j < n; j++)
            {
                if ((j > 1) && (vals[j - 1] == 1))
                {
                    if (vals[j - 2] % 2 != 0)
                    {
                        ans += vals[j];
                    }
                    else
                    {
                        ans += vals[j] - 2;
                    }
                }
                else if ((j > 0) && ((vals[j - 1] % 2) != 0))
                {
                    ans += vals[j] - 1;
                }
                else
                {
                    ans += vals[j];
                }

                ans = ans % MOD;
                profit[j] = ans;

                // printf("Idx %d profit %lld\n", j, profit[j]);
            }
        }

        scanf("%d", &q);

        for (i = 0; i < q; i++)
        {
            scanf("%lld", &r);

            if ((vals[n - 1] % 2) == 0)
            {
                if (vals[0] != 1)
                {
                    ans = (((r / n) % MOD) * (profit[n - 1] - 1));
                }
                else
                {
                    ans = (r / n);
                }
                    
                ans %= MOD;
            }
            else
            {
                ans = (((r / n) % MOD) * (profit[n - 1]));
                ans %= MOD;
            }

            if (r % n == 0)
            {
                if (((vals[n - 1] % 2) == 0) && vals[0] != 1)
                {
                    ans++;
                }
            }
            else
            {
                if ((vals[0] == 1) && r > n && (r % n == 1))
                {
                }
                else
                {
                    ans += profit[(r % n) - 1];
                }
            }

            ans %= MOD;

            printf("%lld\n", ans);
        }
    }

    return 0;
}