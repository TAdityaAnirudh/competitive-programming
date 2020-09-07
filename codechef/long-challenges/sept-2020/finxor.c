#include <stdio.h>
#include <math.h>

int main()
{
    int tests;
    int size;
    long long int final_ans = 0;
    long long int total_sum = 0;
    long long int sum_19 = 0;
    long long int bit_mask = 1;
    long long int cur_ans;
    int i, j, k, l;

    scanf("%d", &tests);

    while (tests--)
    {
        sum_19 = 0;
        final_ans = 0;
        bit_mask = 1;

        scanf("%d", &size);
        printf("1 1048576\n");
        fflush(stdout);
        scanf("%lld\n", total_sum);

        total_sum = total_sum - ((long long int)1048576 * size);

        for (i = 0; i < 19; i++)
        {
            printf("1 %lld\n", bit_mask);
            fflush(stdout);
            scanf("%lld", &cur_ans);
            cur_ans = (cur_ans - total_sum) / bit_mask;
            cur_ans = (size - cur_ans) / 2;

            if ((cur_ans % 2) != 0)
            {
                final_ans += bit_mask;
            }

            sum_19 += (bit_mask * cur_ans);
            bit_mask <<= 1;
        }

        cur_ans = (total_sum - sum_19);
        cur_ans /= bit_mask;

        if ((cur_ans % 2) != 0)
        {
            final_ans += bit_mask;
        }

        printf("2 %lld\n", final_ans);
        fflush(stdout);
        scanf("%d", &size);

        if (size == -1)
        {
            return 0;
        }
    }
    
    return 0;
}
