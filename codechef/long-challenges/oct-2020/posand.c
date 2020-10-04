#include <stdio.h>

int powers_of_two[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};

int main()
{
    int tests;
    int n;
    int i, j, k;

    scanf("%d", &tests);

    while (tests--)
    {
        scanf("%d", &n);

        if (n == 1)
        {
            printf("1\n");
            continue;
        }

        i = 0;
        for (j = 0; j < 16; j++)
        {
            if (n == powers_of_two[j])
            {
                i = 1;
            }
        }

        if (i == 1)
        {
            printf("-1\n");
        }
        else if (n == 3)
        {
            printf("2 3 1\n");
        }
        else
        {
            printf("2 3 1 5 4 ");

            i = 6;
            j = 2;

            while (i <= n)
            {
                if (i == powers_of_two[j])
                {
                    // handle power of two case
                    printf("%d %d ", i + 1, i);
                    i = i + 2;
                    j = j + 1;
                }
                else
                {
                    printf("%d ", i);
                    i = i + 1;
                }
            }

            printf("\n");
        }
    }

    return 0;
}