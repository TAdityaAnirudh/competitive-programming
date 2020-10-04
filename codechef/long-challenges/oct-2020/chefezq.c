#include<stdio.h>

int main()
{
    int tests;
    int total_days;
    long long int pending, current, max_per_day;
    long long int cur_day;
    int seen_good_day;

    scanf("%d", &tests);

    while (tests--)
    {
        scanf("%d %lld", &total_days, &max_per_day);
        cur_day = 1;
        pending = 0;
        seen_good_day = 0;

        while (total_days--)
        {
            scanf("%lld", &current);
            pending += current;

            // send as many as you can today
            if (pending < max_per_day)
            {
                pending = 0;
                if (seen_good_day == 0)
                {
                    printf("%lld\n", cur_day);
                }
                
                seen_good_day = 1;
            }
            else
            {
                pending -= max_per_day;
            }

            cur_day++;
        }

        if (0 == seen_good_day)
        {
            if (pending >= max_per_day)
            {
                cur_day += (pending / max_per_day);
            }
            
            printf("%lld\n", cur_day);
        }
    }

    return 0;
}