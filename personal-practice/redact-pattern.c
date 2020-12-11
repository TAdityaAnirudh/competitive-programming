#include <stdio.h>
#include <string.h>

int main()
{
    char input[1001];
    int len;
    int left;
    int right;
    int start = 0;
    int i;
    int j;

    scanf("%s", input);
    len = strlen(input);

    left = 0;
    right = 1;

    while (right < len)
    {
        if (((input[left] - 'A' + 'a') == input[right]) ||
            ((input[right] - 'A' + 'a')) == input[left])
        {
            // remove both characters
            right = right + 1;
            left = left - 1;

            if (left == -1)
            {
                left = right;
                right = right + 1;
                start = left;
            }
        }
        else
        {
            // copy right character next to left and continue
            input[left + 1] = input[right];
            left = left + 1;
            right = right + 1;
        }
    }

    input[left + 1] = 0;
    printf("%s\n", &(input[start]));

    return 0;
}