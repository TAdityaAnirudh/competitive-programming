#include <stdio.h>
#include <math.h>

int inputs[100001];
int unique[100001];
int assigned[100001];
int ans[100001];
int primes[100001];
int primecalc[2000000];

int main()
{
    // find 10^5 primes

    int i, j, k, l;
    j = 0;
    primecalc[2] = 0;
    for (i = 2; j < 100000; i++)
    {
        if (primecalc[i] == 0)
        {
            primes[j] = i;
            j++;

            for (k = i; k < 2000000; k += i)
            {
                primecalc[k] = 1;
            }
        }
    }

    int tests;
    int n = 0;

    scanf("%d", &tests);

    while (tests--)
    {
        for (i = 0; i < n; i++)
        {
            assigned[i] = 0;
            unique[i] = 0;
        }

        // read input
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &inputs[i]);
        }

        // now fill the unique array
        for (i = 0; i < n; i++)
        {
            unique[inputs[i]] = 1;
        }

        j = 0;

        // now assign values
        for (i = 1; i <= n; i++)
        {
            if (unique[i] != 0)
            {
                assigned[i] = primes[j];
                j++;
            }
        }

        for (i = 0; i < n; i++)
        {
            printf("%d ", assigned[inputs[i]]);
        }

        printf("\n");
    }

    return 0;
}