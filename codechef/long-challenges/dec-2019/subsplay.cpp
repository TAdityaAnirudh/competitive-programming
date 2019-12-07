#include <stdio.h>

char input[100001];

int main()
{
    int tests = 0;
    int n;
    int i, j;
    int temp;
    int ans;
    char cur_char;
    int char_last_idx[26];

    scanf("%d", &tests);

    while (tests--)
    {
        scanf("%d", &n);
        scanf("%s", input);
        ans = 1000000;

        for (i = 0; i < 26; i++)
        {
            char_last_idx[i] = -1;
        }

        for (i = 0; i < n; i++)
        {
            j = (int)(input[i] - 'a');
            
            if (char_last_idx[j] >= 0)
            {
                temp = (i - char_last_idx[j]);
                if (ans > temp)
                {
                    ans = temp;
                }
            }

            char_last_idx[j] = i;            
        }

        if (ans == 1000000)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", (n - ans));
        }
    }

    return 0;
}