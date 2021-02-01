#include <stdio.h>
#include <math.h>

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

int main()
{
    int tests;

    scanf("%d", &tests);
    while (tests--)
    {
        int n;
        int c[4];
        int ans;
        int tmp;

        scanf("%d", &n);

        if (n == 1)
        {
            scanf("%d", &c[0]);
            printf("%d\n", c[0]);
        }
        else if (n == 2)
        {
            scanf("%d %d", &c[0], &c[1]);
            printf("%d\n", max(c[0], c[1]));
        }
        else if (n == 3)
        {
            scanf("%d %d %d", &c[0], &c[1], &c[2]);
            ans = max(c[0], c[1] + c[2]);
            tmp = max(c[1], c[0] + c[2]);
            ans = min(ans, tmp);
            tmp = max(c[2], c[0] + c[1]);
            ans = min(ans, tmp);
            printf("%d\n", ans);
        }
        else if (n == 4)
        {
            scanf("%d %d %d %d", &c[0], &c[1], &c[2], &c[3]);
            // one vs 3
            ans = max(c[0], c[1] + c[2] + c[3]);
            tmp = max(c[1], c[0] + c[2] + c[3]);
            ans = min(ans, tmp);
            tmp = max(c[2], c[0] + c[1] + c[3]);
            ans = min(ans, tmp);
            tmp = max(c[3], c[0] + c[2] + c[1]);
            ans = min(ans, tmp);
            // two vs 2
            tmp = max(c[1] + c[0], c[2] + c[3]);
            ans = min(ans, tmp);
            tmp = max(c[0] + c[2], c[1] + c[3]);
            ans = min(ans, tmp);
            tmp = max(c[0] + c[3], c[2] + c[1]);
            ans = min(ans, tmp);
            tmp = max(c[1] + c[2], c[0] + c[3]);
            ans = min(ans, tmp);
            tmp = max(c[1] + c[3], c[2] + c[0]);
            ans = min(ans, tmp);
            printf("%d\n", ans);
        }
    }

    return 0;
}
